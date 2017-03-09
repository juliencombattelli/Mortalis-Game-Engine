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
	m_actionMap = {
		{Action::pause,		Control(sf::Keyboard::P)},
		{Action::accept,	Control(sf::Keyboard::A)},
		{Action::moveUp,	Control(sf::Keyboard::Up)},
		{Action::moveDown,	Control(sf::Keyboard::Down)},
		{Action::moveLeft,	Control(sf::Keyboard::Left)},
		{Action::moveRight,	Control(sf::Keyboard::Right)},
	};
}

KeyboardController::~KeyboardController()
{

}

} // namespace mge


