//============================================================================
// Name        : MapConfig.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 1, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MortalisGameEngine project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef MAPCONFIG_HPP_
#define MAPCONFIG_HPP_

// If needed, replace this include with yours
#include <MGE/Map/TileMap.hpp>

#include <map>
#include <string>

namespace mge
{

// If needed, replace with your custom map class
using Map = mge::TileMap;
using MapData = mge::TileMapData;

// Replace with your tile size (tiles must be square)
const int TileSize = 32;

// Replace with your map directory
const std::string tilesetDirectory = "resources/";

} // namespace mge

#endif // MAPCONFIG_HPP_
