#include "HerosSprite.hpp"
#include <MUL/SFE/SpriteGenerator.hpp>
//#include <Engine/Graphics/Map/TileMapDrawer.hpp>

rpg::HerosSprite::HerosSprite() :
	mul::sfe::AnimatedSprite<std::string>(true,true),
    mSpeed(DEFAULT_SPEED), mWalkSpeed(DEFAULT_SPEED), mRunFactor(DEFAULT_RUN_FACTOR),
    mRunning(false), mAsMoved(false), mMovement(0.0f,0.0f)
{

}

void rpg::HerosSprite::init(const sf::Texture& texture)
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

void rpg::HerosSprite::animate(float elapsedTime)
{
    updateAnimation(elapsedTime);

    reInit();
}

void rpg::HerosSprite::run()
{
    mRunning = true;
    mSpeed = mWalkSpeed*mRunFactor;
}

void rpg::HerosSprite::walk()
{
    mRunning = false;
    mSpeed = mWalkSpeed;
}

void rpg::HerosSprite::moveRight()
{
    play(MoveRight);
    mMovement.x += mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::moveLeft()
{
	play(MoveLeft);
    mMovement.x -= mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::moveUp()
{
	play(MoveUp);
    mMovement.y -= mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::moveDown()
{
	play(MoveDown);
    mMovement.y += mSpeed;
    mAsMoved = true;
}

void rpg::HerosSprite::updateAnimation(float elapsedTime)
{
    if (not mAsMoved)
        stop();

    mAsMoved = false;

    //play(*mCurrentAnimation);

    move(mMovement * elapsedTime);

    if(mRunning == true)
        elapsedTime *= mRunFactor;

    update(sf::seconds(elapsedTime));
}

void rpg::HerosSprite::reInit()
{
    mMovement.x = 0;
    mMovement.y = 0;
}
