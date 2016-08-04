//============================================================================
// Name        : TileMap.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Aug 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of AutotileDecompressor project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include "TileMap.hpp"

namespace mul { namespace sfe
{

TileMap::TileMap()
{
	sf::Image transparent;
	transparent.create(32,32,sf::Color::Transparent);
	m_transparentTile.loadFromImage(transparent);
}

void TileMap::addTileset(int id, sf::Texture& tileset)
{
	m_tilesets[id] = std::make_shared<sf::Texture>(tileset);
}

void TileMap::loadFromMapData(MapData& map)
{
	m_map.name = map.name;
	m_map.size.x = map.column;
	m_map.size.y = map.row;

	int layerCount = static_cast<int>(map.tiles.size() / (map.column*map.row));

	m_map.layers.resize(layerCount);

	for(int l = 0 ; l < layerCount ; l++)
	{
		m_map.layers[l].tiles.clear();

		for(int x = 0 ; x < m_map.size.x ; x++)
		{
			for(int y = 0 ; y < m_map.size.y ; y++)
			{
				int tileIndex = y*m_map.size.x + x + l*m_map.size.x*m_map.size.y;
				int tile = map.tiles[tileIndex] & 0x000FF;
				int autotile = (map.tiles[tileIndex] & 0x0FF00) >> 8;
				int tileset = (map.tiles[tileIndex] & 0xF0000) >> 16;

				sf::Vector2i topLeftCorner((autotile%8)*64,(autotile/8)*96);

				mul::sfe::AutotilerVXAce a;

				if(map.tiles[tileIndex] == 0xFFFFF)
					m_map.layers[l].tiles.emplace_back(m_transparentTile);
				else
				{
					std::array<sf::IntRect,4> minitiles = a.generateTile(tile, topLeftCorner);

					for(int i = 0 ; i < 4 ; i++)
					{
						m_map.layers[l].tiles.emplace_back(*m_tilesets[tileset], minitiles[i]);
						m_map.layers[l].tiles.back().setPosition(
								static_cast<float>(x*32+16*(i&0x1)),
								static_cast<float>(y*32+16*((i>>1)&0x1)));
					}
				}
			}
		}
	}
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto& layer : m_map.layers)
		for(auto& tile : layer.tiles)
			target.draw(tile, states);
}

} // namespace sfe
} // namespace mul



