//============================================================================
// Name        : Autotiler.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Aug 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of AutotileDecompressor project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef AUTOTILER_HPP_
#define AUTOTILER_HPP_

#include <SFML/Graphics/Rect.hpp>

#include <array>
#include <map>

namespace mul { namespace sfe
{

class Autotiler
{
public:

	using MinitileArray = std::array<sf::IntRect,4>;

	virtual ~Autotiler() = default;
	virtual MinitileArray generateTile(int tileId, const sf::Vector2i& autotileTopLeftCorner = {0,0}) = 0;
};


} // namespace sfe
} // namespace mul

#endif // AUTOTILER_HPP_
