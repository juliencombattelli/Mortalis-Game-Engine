//============================================================================
// Name        : Keyboard.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 27 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef MUL_SFE_KEYBOARD_HPP_
#define MUL_SFE_KEYBOARD_HPP_

#if __cplusplus < 201103L
  #error This library needs at least a C++11 compliant compiler
#endif

#include <SFML/Window/Keyboard.hpp>
#include <vector>

namespace mul { namespace sfe
{

class Keyboard : public sf::Keyboard
{
public:

	static bool areKeyPressed(std::vector<sf::Keyboard::Key> keys);
};

} // namespace sfe
} // namespace mul

#endif // MUL_SFE_KEYBOARD_HPP_
