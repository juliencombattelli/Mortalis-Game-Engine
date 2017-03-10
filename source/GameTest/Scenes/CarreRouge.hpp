#ifndef CARREROUGE_HPP_INCLUDED
#define CARREROUGE_HPP_INCLUDED

#include <MGE/Core/Scene/Scene.hpp>

namespace rpg
{

class CarreRouge : public mge::Scene
{
public:
    CarreRouge(mge::ResourceManager& resourceManager);
    virtual ~CarreRouge();

    virtual void handleEvent(sf::Event& event, const mge::InputManager& input);
    virtual void update(float elapsedTime);
    virtual void draw(sf::RenderTarget& window);

    virtual void pause();
    virtual void resume();

private:

    sf::RectangleShape mRectangle;
    uint16_t mSpeed;
};

}

#endif // CARREROUGE_HPP_INCLUDED
