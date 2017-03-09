#include <GameTest/Scenes/CarreRouge.hpp>
#include <MGE/Input/InputManager.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace rpg
{

CarreRouge::CarreRouge(mge::ResourceManager& resourceManager) :
	mRectangle(), mSpeed(150)
{
    mRectangle.setSize(sf::Vector2f(50, 50));
    mRectangle.setFillColor(sf::Color::Red);
    mRectangle.setPosition(50, 50);
}

CarreRouge::~CarreRouge()
{

}

void CarreRouge::handleEvent(sf::Event& event, const mge::InputManager& keyboard)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
        //mEvent.createState(StateID::MENU);
        //LOGE(SeverityInfo, "State <MENU> created");
    }

}

void CarreRouge::update(float elapsedTime)
{
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    //    mRectangle.move( 0,-mSpeed*elapsedTime);
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    //    mRectangle.move( 0,+mSpeed*elapsedTime);
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    //    mRectangle.move(-mSpeed*elapsedTime, 0);
    //if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    //    mRectangle.move(+mSpeed*elapsedTime, 0);
    static int direction = 0;
    switch(direction)
    {
        case 0:
        {
            if(mRectangle.getPosition().x>=700)
                direction = 1;
            else
                mRectangle.move(+mSpeed*elapsedTime, 0);
        }
        break;

        case 1:
        {
            if(mRectangle.getPosition().y>=500)
                direction = 2;
            else
                mRectangle.move( 0,+mSpeed*elapsedTime);
        }
        break;

        case 2:
        {
            if(mRectangle.getPosition().x<=50)
                direction = 3;
            else
                mRectangle.move(-mSpeed*elapsedTime, 0);
        }
        break;

        case 3:
        {
            if(mRectangle.getPosition().y<=50)
                direction = 0;
            else
                mRectangle.move( 0,-mSpeed*elapsedTime);
        }
        break;

        default: break;
    }
}

void CarreRouge::draw(sf::RenderTarget& window)
{
    window.draw(mRectangle);
}

void CarreRouge::pause()
{

}

void CarreRouge::resume()
{

}

}
