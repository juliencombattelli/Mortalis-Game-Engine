//============================================================================
// Name        : ActionConfig.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef ACTIONCONFIG_HPP_
#define ACTIONCONFIG_HPP_

#include <cstdint>
#include <vector>

namespace mge
{

// Add your custom actions here
enum class Action : std::int8_t
{
	pause,
	accept,
	refuse,
	moveUp,
	moveDown,
	moveLeft,
	moveRight,

	count,     ///< DO NOT EDIT
	invalid    ///< DO NOT EDIT
};

// Register your custom actions in this vector
const std::vector<Action> directionalActions
{
	Action::moveUp, Action::moveDown, Action::moveLeft, Action::moveRight
};

} // namespace mge

#endif // ACTIONCONFIG_HPP_
