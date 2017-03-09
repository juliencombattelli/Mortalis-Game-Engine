//============================================================================
// Name        : Joystick.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 02 mar. 2017
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef MUL_SFE_JOYSTICK_HPP_
#define MUL_SFE_JOYSTICK_HPP_

#if __cplusplus < 201103L
  #error This library needs at least a C++11 compliant compiler
#endif

#include <SFML/Window/Joystick.hpp>
#include <vector>

namespace mul { namespace sfe
{

/*
 * Return the id of the first joystick corresponding to the vendorId and productId
 * Return sf::Joystick::Count if the research failed
 */
unsigned int scanJoysticks(unsigned int vendorId, unsigned int productId);

} // namespace sfe
} // namespace mul

#endif // MUL_SFE_JOYSTICK_HPP_
