//============================================================================
// Name        : KeyManager.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#include <MGE/Input/Keyboard/KeyManager.hpp>
#include <SFML/System/Clock.hpp>

namespace mge
{

namespace priv
{

class KeyManagerImpl
{
	friend class mge::KeyManager;

	struct KeyState
	{
		bool isKeyPressed;
		bool isKeyPressedOnce;
		bool isKeyPressedCont;
	};

	KeyManagerImpl() :
		m_key(sf::Keyboard::Unknown),
		m_state{false,false,false},
		m_FSM_state(FSMState::keyNoPressed)
	{

	}

	KeyManagerImpl(sf::Keyboard::Key key) :
		m_key(key),
		m_state{false,false,false},
		m_FSM_state(FSMState::keyNoPressed)
	{

	}

	void update()
	{
		m_state.isKeyPressedOnce = false;
		m_state.isKeyPressedCont = false;

		const bool isKeyPressed = sf::Keyboard::isKeyPressed(m_key);

		m_state.isKeyPressed = isKeyPressed;

		switch (m_FSM_state)
		{
			case FSMState::keyNoPressed:
			{
				if (isKeyPressed)
				{
					m_state.isKeyPressedOnce = true;
					m_state.isKeyPressedCont = true;
					m_timer.restart();

					m_FSM_state = FSMState::keyPressed;
				}
			}
			break;

			case FSMState::keyPressed:
			{
				if (isKeyPressed and (m_timer.getElapsedTime().asMilliseconds() >= 1000))
				{
					m_state.isKeyPressedCont = true;
					m_state.isKeyPressedOnce = false;

					m_timer.restart();

					m_FSM_state = FSMState::keyContPressed;
				}
				else if (not isKeyPressed)
				{
					m_state.isKeyPressedOnce = false;
					m_state.isKeyPressedCont = false;

					m_FSM_state = FSMState::keyNoPressed;
				}
			}
			break;

			case FSMState::keyContPressed:
			{
				if (not isKeyPressed)
				{
					m_state.isKeyPressedOnce = false;
					m_state.isKeyPressedCont = false;

					m_FSM_state = FSMState::keyNoPressed;
				}
				else if(isKeyPressed and (m_timer.getElapsedTime().asMilliseconds() >= 50))
				{
					m_state.isKeyPressedOnce = false;
					m_state.isKeyPressedCont = true;

					m_timer.restart();

					m_FSM_state = FSMState::keyContPressed;
				}
			}
			break;

			default:
			{
				m_state.isKeyPressedOnce = false;
				m_state.isKeyPressedCont = false;
				m_FSM_state = FSMState::keyContPressed;
			}
		}
	}

	sf::Keyboard::Key m_key;

	KeyState m_state;

	enum class FSMState : int8_t {keyNoPressed, keyPressed, keyContPressed} m_FSM_state;

	sf::Clock m_timer;
};

} // namespace priv

KeyManager::KeyManager() :
	m_impl(std::unique_ptr<priv::KeyManagerImpl>(new priv::KeyManagerImpl()))
{

}

KeyManager::KeyManager(sf::Keyboard::Key key) :
	m_impl(std::unique_ptr<priv::KeyManagerImpl>(new priv::KeyManagerImpl(key)))
{

}

KeyManager::KeyManager(KeyManager&& keyManager) :
	m_impl(std::move(keyManager.m_impl))
{

}

KeyManager& KeyManager::operator=(KeyManager&& keyManager)
{
	m_impl = std::move(keyManager.m_impl);
	return *this;
}

KeyManager::~KeyManager()
{

}

void KeyManager::update()
{
	m_impl->update();
}

void KeyManager::changeKeyCode(sf::Keyboard::Key new_key)
{
	m_impl->m_key = new_key;
}

bool KeyManager::isPressed() const
{
	return m_impl->m_state.isKeyPressed;
}

bool KeyManager::isPressedOnce() const
{
	return m_impl->m_state.isKeyPressedOnce;
}

bool KeyManager::isPressedCont() const
{
	return m_impl->m_state.isKeyPressedCont;
}

} // namespace mge
