//============================================================================
// Name        : KeyManager.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef KEYMANAGER_HPP_
#define KEYMANAGER_HPP_

#include <SFML/Window/Keyboard.hpp>
#include <memory>

namespace mge
{

namespace priv { class KeyManagerImpl; }

class KeyManager
{
public:

	KeyManager();
	KeyManager(sf::Keyboard::Key key);

	KeyManager(const KeyManager&) = delete;
	KeyManager& operator=(const KeyManager&) = delete;

	KeyManager(KeyManager&&);
	KeyManager& operator=(KeyManager&&);

	~KeyManager();

	void update();

	void changeKeyCode(sf::Keyboard::Key new_key);

	bool isPressed() const;
	bool isPressedOnce() const;
	bool isPressedCont() const;

private:

    std::unique_ptr<priv::KeyManagerImpl> m_impl;
};

} // namespace mge

#endif // KEYMANAGER_H_
