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

namespace math_constants {

template <typename T>
constexpr auto pi = static_cast<T>(3.14159265358979323846);

} // namespace math_constants

float r(int a, int b = 0)
{
    const auto randf = static_cast<float>(std::rand() % (static_cast<int64_t>(a) * 1000));
    return (randf + static_cast<float>(b) * 1000) / 1000.F;
}

struct Body {
    Body(const sf::Vector2f& p, const sf::Vector2f& d, float rd = 0.F)
        : position(p)
        , direction(d)
        , rotationd(rd)
        , alpha(1.F)
    {
    }

    sf::Vector2f position;
    sf::Vector2f direction;
    float rotation = 0.F, rotationd, alpha;
};

using Renderable = std::shared_ptr<sf::Shape>;

struct Targetable {
    std::function<void(int)> onTarget {};
};

struct Clickable {
    std::function<void(int)> onClick {};
};

class PointerTargetSystem {
public:
    explicit PointerTargetSystem(sf::RenderWindow& t)
        : target(t)
    {
    }

    void update(entt::registry& registry, float /*dt*/)
    {
        const auto pointer = static_cast<sf::Vector2f>(sf::Mouse::getPosition(target));

        registry.view<Targetable, Body>().each([&](auto& targetable, auto& body) {
            const auto body_bounds = sf::FloatRect { body.position, body.direction };
            if (body_bounds.contains(pointer)) {
                if (targetable.onTarget) {
                    targetable.onTarget(1);
                }
            }
        });
    }

private:
    sf::RenderWindow& target;
};

class PointerClickSystem {
public:
    explicit PointerClickSystem(sf::RenderWindow& t)
        : target(t)
    {
    }

    void update(entt::registry& registry, float /*dt*/)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            const auto pointer = static_cast<sf::Vector2f>(sf::Mouse::getPosition(target));
            registry.view<Clickable, Body>().each([&](auto& clickable, auto& body) {
                const auto body_bounds = sf::FloatRect { body.position, body.direction };
                if (body_bounds.contains(pointer)) {
                    if (clickable.onClick) {
                        clickable.onClick(1);
                    }
                }
            });
        }
    }

private:
    sf::RenderWindow& target;
};

// Render all Renderable entities and draw some informational text.
class RenderSystem {
public:
    explicit RenderSystem(sf::RenderWindow& t, sf::Font& font)
        : target(t)
    {
        text.setFont(font);
        text.setPosition(sf::Vector2f(2, 2));
        text.setCharacterSize(18);
        text.setFillColor(sf::Color::White);
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
        if (last_update >= 0.5F) {
            std::ostringstream out;
            const auto fps = frame_count / last_update;
            out << registry.alive() << " entities (" << static_cast<int>(fps) << " fps)";
            text.setString(out.str());
            last_update = 0.0F;
            frame_count = 0.0F;
        }
        target.draw(text);
    }

private:
    float last_update = 0.0;
    float frame_count = 0.0;
    sf::RenderWindow& target;
    sf::Text text;
};

class Application {
public:
    explicit Application(sf::RenderWindow& target, sf::Font& font)
        : m_renderSystem(target, font)
        , m_pointerTargetSystem(target)
        , m_pointerClickSystem(target)
    {
        auto entity = m_registry.create();

        auto& body = m_registry.emplace_or_replace<Body>(entity, sf::Vector2f(100, 100), sf::Vector2f(80, 40));

        m_registry.emplace_or_replace<Targetable>(entity, [](int id) {
            std::cout << "entity #" << id << " targeted\n";
        });

        m_registry.emplace_or_replace<Clickable>(entity, [](int id) {
            std::cout << "entity #" << id << " clicked\n";
        });

        Renderable shape(new sf::RectangleShape({ body.direction.x, body.direction.y }));
        shape->setFillColor(sf::Color(
            static_cast<sf::Uint8>(r(128, 127)),
            static_cast<sf::Uint8>(r(128, 127)),
            static_cast<sf::Uint8>(r(128, 127)),
            255));
        m_registry.emplace_or_replace<Renderable>(entity, shape);
    }

    void update(float dt)
    {
        m_dispatcher.update();

        m_pointerTargetSystem.update(m_registry, dt);
        m_pointerClickSystem.update(m_registry, dt);
        m_renderSystem.update(m_registry, dt);
    }

private:
    entt::registry m_registry;
    entt::dispatcher m_dispatcher {};

    RenderSystem m_renderSystem;
    PointerTargetSystem m_pointerTargetSystem;
    PointerClickSystem m_pointerClickSystem;
};

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    sf::RenderWindow window(sf::VideoMode { 800, 600 }, "EnTT Example" /*, sf::Style::Fullscreen*/);
    window.setVerticalSyncEnabled(true);
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