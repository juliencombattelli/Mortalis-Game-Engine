//============================================================================
// Name        : Joystick.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 02 mar. 2017
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================


#include <MUL/SFE/Joystick.hpp>

namespace mul { namespace sfe
{

unsigned int scanJoysticks(unsigned int vendorId, unsigned int productId)
{
	std::vector<unsigned int> joysticksId;

	for(unsigned int i = 0 ; i < sf::Joystick::Count ; i++)
		if(sf::Joystick::isConnected(i)/* and sf::Joystick::getIdentification(i).vendorId == vendorId and sf::Joystick::getIdentification(i).productId == productId*/)
			return i;
	return sf::Joystick::Count;
}

} // namespace sfe
} // namespace mul
