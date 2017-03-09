/*
 * KeyboardController.cpp
 *
 *  Created on: 27 févr. 2017
 *      Author: JulienCombattelli
 */

#include <MGE/Input/KeyboardController.hpp>
#include <MGE/Config/ActionConfig.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace mge
{

KeyboardController::KeyboardController()
{
	m_actionMap[Action::pause] = std::make_unique<KeyboardButton>(sf::Keyboard::P);
	m_actionMap[Action::accept] = std::make_unique<KeyboardButton>(sf::Keyboard::A);
	m_actionMap[Action::moveUp] = std::make_unique<KeyboardButton>(sf::Keyboard::Up);
	m_actionMap[Action::moveDown] = std::make_unique<KeyboardButton>(sf::Keyboard::Down);
	m_actionMap[Action::moveLeft] = std::make_unique<KeyboardButton>(sf::Keyboard::Left);
	m_actionMap[Action::moveRight] = std::make_unique<KeyboardButton>(sf::Keyboard::Right);
}

KeyboardController::~KeyboardController()
{

}

} // namespace mge


