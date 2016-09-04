//============================================================================
// Name        : Keyboard.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef KEYBOARD_HPP_
#define KEYBOARD_HPP_

#include <MGE/Config/ActionConfig.hpp>
#include <MGE/Input/Keyboard/DPad.hpp>
#include <MGE/Input/Keyboard/KeyManager.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <MUL/Bimap/Bimap.hpp>
#include <array>
#include <memory>

namespace mge
{

using String2KeyBimap = mul::bimap::Bimap<std::string,sf::Keyboard::Key>;
using Action2StringBimap = mul::bimap::Bimap<Action,std::string>;
using ActionKeyBinding = mul::bimap::Bimap<Action,sf::Keyboard::Key>;

class Keyboard
{
public:

    Keyboard();
    Keyboard(const Keyboard&) = delete;
    Keyboard& operator=(const Keyboard&) = delete;
    ~Keyboard();

    void changeActionKey(Action key, sf::Keyboard::Key newCode);

	void update();

	bool isKeyPressed(Action action) const { return m_actionMap.at(action).isPressed(); }
	bool isKeyPressedOnce(Action action) const { return m_actionMap.at(action).isPressedOnce(); }
	bool isKeyPressedCont(Action action) const { return m_actionMap.at(action).isPressedCont(); }
	bool isDKeyPressed(Action action) const { return m_DPad.isPressed(action); }

	static const Action2StringBimap action2stringBimap;
	static const String2KeyBimap 	string2keyBimap;
	static const ActionKeyBinding 	defaultActionKeyBinding;

private:

    std::map<Action, KeyManager> m_actionMap;
    DPad m_DPad;
};

} // namespace mge

#endif // KEYBOARD_HPP_
