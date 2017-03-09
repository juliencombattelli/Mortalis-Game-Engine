/*
 * Dualshock4Controller.cpp
 *
 *  Created on: 28 févr. 2017
 *      Author: JulienCombattelli
 */

#include <MGE/Input/Dualshock4Controller.hpp>

namespace mge
{

Dualshock4Controller::Dualshock4Controller() : m_controllerID(mul::sfe::scanJoysticks(VendorID, ProductID))
{
	m_actionMap[Action::pause] = std::make_unique<JoystickButton>(m_controllerID, ButtonPS);
	m_actionMap[Action::accept] = std::make_unique<JoystickButton>(m_controllerID, ButtonCross);
	m_actionMap[Action::moveUp] = std::make_unique<NegativAxe>(m_controllerID, sf::Joystick::Y);
	m_actionMap[Action::moveDown] = std::make_unique<PositivAxe>(m_controllerID, sf::Joystick::Y);
	m_actionMap[Action::moveLeft] = std::make_unique<NegativAxe>(m_controllerID, sf::Joystick::X);
	m_actionMap[Action::moveRight] = std::make_unique<PositivAxe>(m_controllerID, sf::Joystick::X);
}

Dualshock4Controller::~Dualshock4Controller()
{

}

} // namespace mge

