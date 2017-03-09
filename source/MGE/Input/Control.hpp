/*
 * Control.hpp
 *
 *  Created on: 9 mars 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_CONTROL_HPP_
#define MGE_INPUT_CONTROL_HPP_

#include <functional>

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

namespace mge
{

class Control
{
public:

	virtual ~Control() {}

	virtual bool getState() const = 0;
};

class KeyboardButton : public Control
{
public:

	KeyboardButton(int buttonId) : m_id(buttonId) {}

	virtual bool getState() const override
	{
		if(m_id != -1)
			return sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(m_id));
		else
			return false;
	}

private:

	int m_id;
};

class JoystickButton : public Control
{
public:

	JoystickButton(int controllerId, int buttonId) : m_id(buttonId), m_controllerId(controllerId) {}

	virtual bool getState() const override
	{
		if(m_id != -1 && m_controllerId != -1)
			return sf::Joystick::isButtonPressed(m_controllerId, m_id);
		else
			return false;
	}

private:

	int m_id;
	int m_controllerId;
};

class NegativAxe : public Control
{
public:

	NegativAxe(int controllerId, int buttonId) : m_id(buttonId), m_controllerId(controllerId) {}

	virtual bool getState() const override
	{
		float axeValue = sf::Joystick::getAxisPosition(m_controllerId, static_cast<sf::Joystick::Axis>(m_id));
		return (axeValue < -50) ? true : false;
	}

private:

	int m_id;
	int m_controllerId;
};

class PositivAxe : public Control
{
public:

	PositivAxe(int controllerId, int buttonId) : m_id(buttonId), m_controllerId(controllerId) {}

	virtual bool getState() const override
	{
		float axeValue = sf::Joystick::getAxisPosition(m_controllerId, static_cast<sf::Joystick::Axis>(m_id));
		return (50 < axeValue) ? true : false;
	}

private:

	int m_id;
	int m_controllerId;
};

} // namespace mge

#endif /* MGE_INPUT_CONTROL_HPP_ */
