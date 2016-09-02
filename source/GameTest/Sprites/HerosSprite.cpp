#include "HerosSprite.hpp"
#include <MUL/SFE/SpriteGenerator.hpp>
//#include <Engine/Graphics/Map/TileMapDrawer.hpp>

namespace game
{

HerosSprite::HerosSprite() :
	mul::sfe::AnimatedSprite<std::string>(true,true),
    m_speed(DEFAULT_SPEED), m_walkSpeed(DEFAULT_SPEED), m_runFactor(DEFAULT_RUN_FACTOR),
    m_running(false), m_asMoved(false), m_movement(0.0f,0.0f)
{

}

void HerosSprite::init(const sf::Texture& texture)
{
	mul::sfe::SpriteGenerator sg(texture, {12,8}, {32,32});
	mul::sfe::AnimatedSprite<std::string> as(true, true);

	setPosition(400, 300);

	addFrame(MoveDown,  sg.get(1), sf::seconds(0.25));
	addFrame(MoveDown,  sg.get(2), sf::seconds(0.25));
	addFrame(MoveDown,  sg.get(1), sf::seconds(0.25));
	addFrame(MoveDown,  sg.get(0), sf::seconds(0.25));

	addFrame(MoveLeft,  sg.get(13), sf::seconds(0.25));
	addFrame(MoveLeft,  sg.get(14), sf::seconds(0.25));
	addFrame(MoveLeft,  sg.get(13), sf::seconds(0.25));
	addFrame(MoveLeft,  sg.get(12), sf::seconds(0.25));

	addFrame(MoveRight, sg.get(25), sf::seconds(0.25));
	addFrame(MoveRight, sg.get(26), sf::seconds(0.25));
	addFrame(MoveRight, sg.get(25), sf::seconds(0.25));
	addFrame(MoveRight, sg.get(24), sf::seconds(0.25));

	addFrame(MoveUp,    sg.get(37), sf::seconds(0.25));
	addFrame(MoveUp,    sg.get(38), sf::seconds(0.25));
	addFrame(MoveUp,    sg.get(37), sf::seconds(0.25));
	addFrame(MoveUp,    sg.get(36), sf::seconds(0.25));

	play(MoveDown);
}

void HerosSprite::animate(float elapsedTime)
{
    updateAnimation(elapsedTime);

    reInit();
}

void HerosSprite::run()
{
    m_running = true;
    m_speed = m_walkSpeed*m_runFactor;
}

void HerosSprite::walk()
{
    m_running = false;
    m_speed = m_walkSpeed;
}

void HerosSprite::moveRight()
{
    play(MoveRight);
    m_movement.x += m_speed;
    m_asMoved = true;
}

void HerosSprite::moveLeft()
{
	play(MoveLeft);
    m_movement.x -= m_speed;
    m_asMoved = true;
}

void HerosSprite::moveUp()
{
	play(MoveUp);
    m_movement.y -= m_speed;
    m_asMoved = true;
}

void HerosSprite::moveDown()
{
	play(MoveDown);
    m_movement.y += m_speed;
    m_asMoved = true;
}

void HerosSprite::updateAnimation(float elapsedTime)
{
    if (not m_asMoved)
        stop();

    m_asMoved = false;

    //play(*mCurrentAnimation);

    move(m_movement * elapsedTime);

    if(m_running == true)
        elapsedTime *= m_runFactor;

    update(sf::seconds(elapsedTime));
}

void HerosSprite::reInit()
{
    m_movement.x = 0;
    m_movement.y = 0;
}

} // namespace game
