//============================================================================
// Name        : HerosSprite.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef HEROSSPRITE_HPP_INCLUDED
#define HEROSSPRITE_HPP_INCLUDED

#include <MUL/SFE/AnimatedSprite.hpp>
#include <string>

namespace game
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

    float m_speed;
    float m_walkSpeed;
    float m_runFactor;
    bool m_running;
    bool m_asMoved;

    sf::Vector2f m_movement;

    void updateAnimation(float elapsedTime);
    void reInit();
};

} // namespace game

#endif // HEROSSPRITE_HPP_INCLUDED
