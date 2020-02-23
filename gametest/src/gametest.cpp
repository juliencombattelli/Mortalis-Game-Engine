/**
 * This is an example of using EntityX.
 *
 * It is an SFML2 application that spawns 100 random circles on a 2D plane
 * moving in random directions. If two circles collide they will explode and
 * emit particles.
 *
 * This illustrates a bunch of EC/EntityX concepts:
 *
 * - Separation of data via components.
 * - Separation of logic via systems.
 * - Use of events (colliding bodies trigger a CollisionEvent).
 *
 * Compile with:
 *
 *    c++ -I.. -O3 -std=c++11 -Wall -lsfml-system -lsfml-window -lsfml-graphics -lentityx example.cc -o example
 */
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdlib>
#include <entt/entt.hpp>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using std::cerr;
using std::cout;
using std::endl;

float r(int a, float b = 0)
{
    return static_cast<float>(std::rand() % (a * 1000) + b * 1000) / 1000.F;
}

struct Body {
    Body(const sf::Vector2f& position, const sf::Vector2f& direction, float rotationd = 0.F)
        : position(position)
        , direction(direction)
        , rotationd(rotationd)
        , alpha(0.F)
    {
    }

    sf::Vector2f position;
    sf::Vector2f direction;
    float rotation = 0.F, rotationd, alpha;
};

using Renderable = std::shared_ptr<sf::Shape>;

struct Particle {
    explicit Particle(sf::Color colour, float radius, float duration)
        : colour(colour)
        , radius(radius)
        , alpha(colour.a)
        , d(colour.a / duration)
    {
    }

    sf::Color colour;
    float radius, alpha, d;
};

struct Collideable {
    explicit Collideable(float radius)
        : radius(radius)
    {
    }

    float radius;
};

// Emitted when two entities collide.
struct CollisionEvent {
    CollisionEvent(entt::entity left, entt::entity right)
        : left(left)
        , right(right)
    {
    }

    entt::entity left, right;
};

class SpawnSystem {
public:
    explicit SpawnSystem(sf::RenderTarget& target, int count)
        : size(target.getSize())
        , count(count)
    {
    }

    void update(entt::registry& registry, float dt)
    {
        int c = 0;
        registry.view<Collideable>().each([&](auto&) { ++c; });

        for (int i = 0; i < count - c; i++) {
            auto entity = registry.create();

            // Mark as collideable (explosion particles will not be collideable).
            auto collideable = registry.assign<Collideable>(entity, r(10, 5));

            // "Physical" attributes.
            registry.assign<Body>(entity,
                sf::Vector2f(r(size.x), r(size.y)),
                sf::Vector2f(r(100, -50), r(100, -50)));

            // Shape to apply to entity.
            Renderable shape(new sf::CircleShape(collideable.radius));
            shape->setFillColor(sf::Color(r(128, 127), r(128, 127), r(128, 127), 0));
            shape->setOrigin(collideable.radius, collideable.radius);
            registry.assign<Renderable>(entity, shape);
        }
    }

private:
    sf::Vector2u size;
    int count;
};

// Updates a body's position and rotation.
struct BodySystem {
    void update(entt::registry& registry, float dt)
    {
        const float fdt = static_cast<float>(dt);
        registry.view<Body>().each([fdt](auto& body) {
            body.position += body.direction * fdt;
            body.rotation += body.rotationd * fdt;
            body.alpha = std::min(1.0f, body.alpha + fdt);
        });
    };
};

// Bounce bodies off the edge of the screen.
class BounceSystem {
public:
    explicit BounceSystem(sf::RenderTarget& target)
        : size(target.getSize())
    {
    }

    void update(entt::registry& registry, float dt)
    {
        registry.view<Body>().each([this](auto& body) {
            if (body.position.x + body.direction.x < 0 || body.position.x + body.direction.x >= size.x)
                body.direction.x = -body.direction.x;
            if (body.position.y + body.direction.y < 0 || body.position.y + body.direction.y >= size.y)
                body.direction.y = -body.direction.y;
        });
    }

private:
    sf::Vector2u size;
};

// Determines if two Collideable bodies have collided. If they have it emits a
// CollisionEvent. This is used by ExplosionSystem to create explosion
// particles, but it could be used by a SoundSystem to play an explosion
// sound, etc..
//
// Uses a fairly rudimentary 2D partition system, but performs reasonably well.
class CollisionSystem {
    static const int PARTITIONS = 200;

    struct Candidate {
        sf::Vector2f position;
        float radius;
        entt::entity entity;
    };

public:
    explicit CollisionSystem(sf::RenderTarget& target)
        : size(target.getSize())
    {
        size.x = size.x / PARTITIONS + 1;
        size.y = size.y / PARTITIONS + 1;
    }

    void update(entt::registry& registry, entt::dispatcher& dispatcher, float dt)
    {
        reset();
        collect(registry);
        collide(dispatcher);
    };

private:
    std::vector<std::vector<Candidate>> grid;
    sf::Vector2u size;

    void reset()
    {
        grid.clear();
        grid.resize(size.x * size.y);
    }

    void collect(entt::registry& registry)
    {
        registry.view<Body, Collideable>().each([this](auto entity, auto& body, auto& collideable) {
            unsigned int
                left
                = static_cast<int>(body.position.x - collideable.radius) / PARTITIONS,
                top = static_cast<int>(body.position.y - collideable.radius) / PARTITIONS,
                right = static_cast<int>(body.position.x + collideable.radius) / PARTITIONS,
                bottom = static_cast<int>(body.position.y + collideable.radius) / PARTITIONS;
            Candidate candidate { body.position, collideable.radius, entity };
            unsigned int slots[4] = {
                left + top * size.x,
                right + top * size.x,
                left + bottom * size.x,
                right + bottom * size.x,
            };
            grid[slots[0]].push_back(candidate);
            if (slots[0] != slots[1])
                grid[slots[1]].push_back(candidate);
            if (slots[1] != slots[2])
                grid[slots[2]].push_back(candidate);
            if (slots[2] != slots[3])
                grid[slots[3]].push_back(candidate);
        });
    }

    void collide(entt::dispatcher& dispatcher)
    {
        for (const std::vector<Candidate>& candidates : grid) {
            for (const Candidate& left : candidates) {
                for (const Candidate& right : candidates) {
                    if (left.entity == right.entity)
                        continue;
                    if (collided(left, right))
                        dispatcher.trigger<CollisionEvent>(left.entity, right.entity);
                }
            }
        }
    }

    float length(const sf::Vector2f& v)
    {
        return std::sqrt(v.x * v.x + v.y * v.y);
    }

    bool collided(const Candidate& left, const Candidate& right)
    {
        return length(left.position - right.position) < left.radius + right.radius;
    }
};

// Fade out and then remove particles.
class ParticleSystem {
public:
    void update(entt::registry& registry, float dt)
    {
        registry.view<Particle>().each([&](auto entity, auto& particle) {
            particle.alpha -= particle.d * dt;
            if (particle.alpha <= 0) {
                registry.destroy(entity);
            } else {
                particle.colour.a = particle.alpha;
            }
        });
    }
};

// Renders all explosion particles efficiently as a quad vertex array.
class ParticleRenderSystem {
public:
    explicit ParticleRenderSystem(sf::RenderTarget& target)
        : target(target)
    {
    }

    void update(entt::registry& registry, float dt)
    {
        sf::VertexArray vertices(sf::Quads);
        registry.view<Particle, Body>().each([&vertices](auto& particle, auto& body) {
            const float r = particle.radius;
            // Spin the particles.
            sf::Transform transform;
            transform.rotate(body.rotation);
            vertices.append(sf::Vertex(body.position + transform.transformPoint(sf::Vector2f(-r, -r)), particle.colour));
            vertices.append(sf::Vertex(body.position + transform.transformPoint(sf::Vector2f(r, -r)), particle.colour));
            vertices.append(sf::Vertex(body.position + transform.transformPoint(sf::Vector2f(r, r)), particle.colour));
            vertices.append(sf::Vertex(body.position + transform.transformPoint(sf::Vector2f(-r, r)), particle.colour));
        });
        target.draw(vertices);
    }

private:
    sf::RenderTarget& target;
};

// For any two colliding bodies, destroys the bodies and emits a bunch of bodgy explosion particles.
class ExplosionSystem {
public:
    void update(entt::registry& registry, float dt)
    {
        for (auto entity : collided) {
            emit_particles(registry, entity);
            registry.destroy(entity);
        }
        collided.clear();
    }

    void emit_particles(entt::registry& registry, entt::entity entity)
    {
        const auto body = registry.get<Body>(entity);
        const auto renderable = registry.get<Renderable>(entity);
        const auto collideable = registry.get<Collideable>(entity);

        sf::Color colour = renderable->getFillColor();
        colour.a = 200;

        float area = (M_PI * collideable.radius * collideable.radius) / 3.0;
        for (int i = 0; i < area; i++) {
            float rotationd = r(720, 180);
            if (std::rand() % 2 == 0)
                rotationd = -rotationd;

            float offset = r(collideable.radius, 1);
            float angle = r(360) * M_PI / 180.0;

            auto particle = registry.create();
            registry.assign<Body>(particle,
                body.position + sf::Vector2f(offset * cos(angle), offset * sin(angle)),
                body.direction + sf::Vector2f(offset * 2 * cos(angle), offset * 2 * sin(angle)),
                rotationd);

            float radius = r(3, 1);
            registry.assign<Particle>(particle, colour, radius, radius / 2);
        }
    }

    void receive(const CollisionEvent& collision)
    {
        // Events are immutable, so we can't destroy the entities here. We defer
        // the work until the update loop.
        collided.insert(collision.left);
        collided.insert(collision.right);
    }

private:
    std::unordered_set<entt::entity> collided;
};

// Render all Renderable entities and draw some informational text.
class RenderSystem {
public:
    explicit RenderSystem(sf::RenderTarget& target, sf::Font& font)
        : target(target)
    {
        text.setFont(font);
        text.setPosition(sf::Vector2f(2, 2));
        text.setCharacterSize(18);
        text.setColor(sf::Color::White);
    }

    void update(entt::registry& registry, float dt)
    {
        registry.view<Body, Renderable>().each([this](auto& body, auto& renderable) {
            sf::Color fillColor = renderable->getFillColor();
            fillColor.a = sf::Uint8(body.alpha * 255);
            renderable->setFillColor(fillColor);
            renderable->setPosition(body.position);
            renderable->setRotation(body.rotation);
            target.draw(*renderable.get());
        });
        last_update += dt;
        frame_count++;
        if (last_update >= 0.5) {
            std::ostringstream out;
            const double fps = frame_count / last_update;
            out << registry.alive() << " entities (" << static_cast<int>(fps) << " fps)";
            text.setString(out.str());
            last_update = 0.0;
            frame_count = 0.0;
        }
        target.draw(text);
    }

private:
    double last_update = 0.0;
    double frame_count = 0.0;
    sf::RenderTarget& target;
    sf::Text text;
};

class Application {
public:
    explicit Application(sf::RenderTarget& target, sf::Font& font)
        : m_spawnSystem(target, 250)
        , m_bounceSystem(target)
        , m_collisionSystem(target)
        , m_renderSystem(target, font)
        , m_particleRenderSystem(target)
    {
        m_dispatcher.sink<CollisionEvent>().connect<&ExplosionSystem::receive>(m_explosionSystem);
    }

    void update(float dt)
    {
        m_dispatcher.update();

        m_spawnSystem.update(m_registry, dt);
        m_bodySystem.update(m_registry, dt);
        m_bounceSystem.update(m_registry, dt);
        m_collisionSystem.update(m_registry, m_dispatcher, dt);
        m_explosionSystem.update(m_registry, dt);
        m_particleSystem.update(m_registry, dt);
        m_renderSystem.update(m_registry, dt);
        m_particleRenderSystem.update(m_registry, dt);
    }

private:
    entt::registry m_registry;
    entt::dispatcher m_dispatcher {};

    SpawnSystem m_spawnSystem;
    BodySystem m_bodySystem;
    BounceSystem m_bounceSystem;
    CollisionSystem m_collisionSystem;
    ExplosionSystem m_explosionSystem;
    ParticleSystem m_particleSystem;
    RenderSystem m_renderSystem;
    ParticleRenderSystem m_particleRenderSystem;
};

int main()
{
    std::srand(std::time(nullptr));

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "EntityX Example", sf::Style::Fullscreen);
    sf::Font font;
    if (!font.loadFromFile("LiberationSans-Regular.ttf")) {
        cerr << "error: failed to load LiberationSans-Regular.ttf" << endl;
        return 1;
    }

    Application app(window, font);

    sf::Clock clock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed:
            case sf::Event::KeyPressed:
                window.close();
                break;

            default:
                break;
            }
        }

        window.clear();
        sf::Time elapsed = clock.restart();
        app.update(elapsed.asSeconds());
        window.display();
    }
}