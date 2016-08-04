//============================================================================
// Name        : Keyboard.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 27 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <MUL/SFE/Keyboard.hpp>

namespace mul { namespace sfe
{

bool Keyboard::areKeyPressed(std::vector<sf::Keyboard::Key> keys)
{
	for(auto key : keys)
		if(not sf::Keyboard::isKeyPressed(key))
			return false;
	return true;
}

} // namespace sfe
} // namespace mul


