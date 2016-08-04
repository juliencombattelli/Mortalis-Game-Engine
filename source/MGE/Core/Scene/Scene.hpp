#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <SFML/Graphics.hpp>
#include <MGE/Input/KeyboardAPI.hpp>

namespace mge
{

// Forward declaration for derived class
class ResourceManager;

class Scene
{
public:

	Scene() = default;
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
    virtual ~Scene() = default;

    virtual void handleEvent(sf::Event& event, const Keyboard& keyboard) = 0;
    virtual void update(float elapsedTime) = 0;
    virtual void draw(sf::RenderTarget& window) = 0;

    virtual void pause() = 0;
    virtual void resume() = 0;
};

} // namespace mge

#endif // SCENE_HPP_
