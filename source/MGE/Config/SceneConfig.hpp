//============================================================================
// Name        : SceneConfig.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 2 juil. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef SCENECONFIG_HPP_
#define SCENECONFIG_HPP_

// Replace this include with yours
#include <MGE/Core/Scene/DummyScene.hpp>
#include <GameTest/Scenes/SceneMap.hpp>

namespace mge
{

// Replace with your custom initial scene class and include it
using InitialScene = game::SceneMap;//DummyScene;

} // namespace mge

#endif // SCENECONFIG_HPP_
