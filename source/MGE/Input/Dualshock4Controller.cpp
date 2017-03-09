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
	m_actionMap = {
		{Action::pause,		Control(ButtonPS)},
		{Action::accept,	Control(ButtonCross)},
		{Action::moveUp,	Control(m_controllerID, sf::Joystick::Y, Control::PositivAxe)},
		{Action::moveDown,	Control(m_controllerID, sf::Joystick::Y, Control::NegativAxe)},
		{Action::moveLeft,	Control(m_controllerID, sf::Joystick::X, Control::PositivAxe)},
		{Action::moveRight,	Control(m_controllerID, sf::Joystick::X, Control::NegativAxe)},
	};
}

Dualshock4Controller::~Dualshock4Controller()
{

}

} // namespace mge

