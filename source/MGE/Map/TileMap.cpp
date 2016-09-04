//============================================================================
// Name        : TileMap.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <MGE/Map/TileMap.hpp>
#include <MGE/Resource/TemplateResource.hpp>

#include <SFML/Graphics/RenderTarget.hpp>

namespace mge
{

TileMap::TileMap(ResourceManager& resourceManager, const std::string& tilesetDirectory, int tileSize) :
	m_resourceManager(resourceManager),
	m_tilesetDirectory(tilesetDirectory),
	m_tileSize(tileSize),
	m_mapData(nullptr)
{

}

void TileMap::load(const TileMapData& mapData)
{
	m_mapData = &mapData;

	createTransparentTile(m_tileSize);

	loadTilesetTextures(mapData);

	int layerCount = getLayerCount(mapData);

	m_mapLayers.resize(layerCount);

	for(int l = 0 ; l < layerCount ; l++)
	{
		m_mapLayers[l].tiles.clear();

		for(int x = 0 ; x < mapData.column ; x++)
		{
			for(int y = 0 ; y < mapData.row ; y++)
			{
				int tileIndex = y*mapData.column + x + l*mapData.column*mapData.row;
				int tileset = (mapData.tiles[tileIndex] & 0xF0000) >> 16;

				if(mapData.tiles[tileIndex] == 0xFFFFF)
					m_mapLayers[l].tiles.emplace_back(m_transparentTile);
				else
				{
					if(mapData.tilesets.at(tileset).isAutotile)
					{
						loadAutotile(mapData, l, tileIndex, tileset, x, y);
					}
					else
					{
						loadTile(mapData, l, tileIndex, tileset, x, y);
					}
				}
			}
		}
	}
}

sf::Vector2f TileMap::getSize() const
{
	return {static_cast<float>(m_mapData->column*m_tileSize),static_cast<float>(m_mapData->row*m_tileSize)};
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for(auto& layer : m_mapLayers)
		for(auto& tile : layer.tiles)
			target.draw(tile, states);
}

void TileMap::loadTilesetTextures(const TileMapData& map)
{
	for(auto& pair : map.tilesets)
	{
		TextureResource resource(m_tilesetDirectory + pair.second.name, m_resourceManager);
		m_tilesetTextureMap[pair.first] = std::make_shared<const sf::Texture>(resource.getResource());
	}
}

void TileMap::createTransparentTile(int tileSize)
{
	sf::Image transparent;
	transparent.create(tileSize,tileSize,sf::Color::Transparent);
	m_transparentTile.loadFromImage(transparent);
}

int TileMap::getLayerCount(const TileMapData& mapData) const
{
	//assert(tiles.size()%(column*row) == 0);
	return mapData.tiles.size() / (mapData.column*mapData.row);
}

void TileMap::loadTile(const TileMapData& mapData,int layerIndex, int tileIndex, int tileset, int x, int y)
{
	int tile = mapData.tiles[tileIndex] & 0x0FFFF;

	sf::IntRect intRect
	(
		(tile%mapData.tilesets.at(tileset).tileNumber.x)*m_tileSize,
		(tile/mapData.tilesets.at(tileset).tileNumber.x)*m_tileSize,
		m_tileSize,
		m_tileSize
	);

	m_mapLayers[layerIndex].tiles.emplace_back(*m_tilesetTextureMap[tileset],intRect);
	m_mapLayers[layerIndex].tiles.back().setPosition(x*m_tileSize, y*m_tileSize);
}

void TileMap::loadAutotile(const TileMapData& mapData, int layerIndex, int tileIndex, int tileset, int x, int y)
{
	int tile = mapData.tiles[tileIndex] & 0x000FF;
	int autotile = (mapData.tiles[tileIndex] & 0x0FF00) >> 8;

	sf::Vector2i topLeftCorner((autotile%8)*m_tileSize*2,(autotile/8)*m_tileSize*3);

	mul::sfe::AutotilerVXAce a;

	std::array<sf::IntRect,4> minitiles = a.generateTile(tile, topLeftCorner);

	for(int i = 0 ; i < 4 ; i++)
	{
		m_mapLayers[layerIndex].tiles.emplace_back(*m_tilesetTextureMap[tileset], minitiles[i]);
		m_mapLayers[layerIndex].tiles.back().setPosition(
			static_cast<float>(x*m_tileSize+(m_tileSize/2)*(i&0x1)),
			static_cast<float>(y*m_tileSize+(m_tileSize/2)*((i>>1)&0x1)));
	}
}

} // namespace mge
