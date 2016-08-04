#ifndef HEROSSPRITE_HPP_INCLUDED
#define HEROSSPRITE_HPP_INCLUDED

#include <MUL/SFE/AnimatedSprite.hpp>
#include <string>

namespace rpg
{

class TileMapDrawer;

class HerosSprite : public mul::sfe::AnimatedSprite<std::string>
{
public:
    HerosSprite();

    void init(const sf::Texture& texture);

    void animate(float elapsedTime);
    void run();
    void walk();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

protected:

    static constexpr float DEFAULT_SPEED = 100.f;
    static constexpr float DEFAULT_RUN_FACTOR = 3.f;

    static constexpr auto MoveUp = "moveUp";
    static constexpr auto MoveDown = "moveDown";
    static constexpr auto MoveLeft = "moveLeft";
    static constexpr auto MoveRight = "moveRight";

    float mSpeed;
    float mWalkSpeed;
    float mRunFactor;
    bool mRunning;
    bool mAsMoved;

    sf::Vector2f mMovement;

    void updateAnimation(float elapsedTime);
    void reInit();
};

}

#endif // HEROSSPRITE_HPP_INCLUDED
