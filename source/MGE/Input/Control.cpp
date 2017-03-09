/*
 * Control.cpp
 *
 *  Created on: 9 mars 2017
 *      Author: JulienCombattelli
 */

#include <MGE/Input/Control.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

namespace mge
{
/*
Control::Control() :
	m_id(-1),
	m_controllerId(-1)
{

}

Control::Control(int buttonId, std::function<bool(const Control&)> pred) :
	m_id(buttonId),
	m_controllerId(-1),
	m_predicate(pred)
{

}

Control::Control(int controllerId, int axeId, std::function<bool(const Control&)> pred) :
	m_id(axeId),
	m_controllerId(controllerId),
	m_predicate(pred)
{

}

bool Control::operator()() const
{
	if(m_id != -1)
		return m_predicate(*this);
	else
		return false;
}

bool Control::KeyboardButton(const Control& ctrl)
{
	if(ctrl.m_id != -1)
		return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(ctrl.m_id));
	else
		return false;
}

bool Control::JoystickButton(const Control& ctrl)
{
	if(ctrl.m_controllerId != -1 && ctrl.m_id != -1)
		return sf::Joystick::isButtonPressed(ctrl.m_controllerId, ctrl.m_id);
	else
		return false;
}

bool Control::NegativAxe(const Control& ctrl)
{
	float axeValue = sf::Joystick::getAxisPosition(ctrl.m_controllerId, static_cast<sf::Joystick::Axis>(ctrl.m_id));
	return (-100 < axeValue && axeValue < -50) ? true : false;
}

bool Control::PositivAxe(const Control& ctrl)
{
	float axeValue = sf::Joystick::getAxisPosition(ctrl.m_controllerId, static_cast<sf::Joystick::Axis>(ctrl.m_id));
	return (50 < axeValue && axeValue < 100) ? true : false;
}
*/
} // namespace mge


