//============================================================================
// Name        : TileMap.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <MUL/SFE/AutotilerVXAce.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <vector>
#include <memory>

namespace mge
{

class ResourceManager;

struct TilesetData
{
	std::string name;
	bool isAutotile;
	sf::Vector2i tileNumber;
	sf::Vector2i autotileNumber;
};

struct TileMapData
{
	std::string name;
	int row;
	int column;
	std::map<int,TilesetData> tilesets;
	std::vector<int> tiles;
};

class TileMap : public sf::Drawable
{
public:

	TileMap(ResourceManager& resourceManager, const std::string& tilesetDirectory, int tileSize);

	void load(const TileMapData& mapData);

	sf::Vector2f getSize() const;

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void loadTilesetTextures(const TileMapData& map);

    void createTransparentTile(int tileSize);

    int getLayerCount(const TileMapData& mapData) const;

    void loadTile(const TileMapData& mapData, int layerIndex, int tileIndex, int tileset, int x, int y);

    void loadAutotile(const TileMapData& mapData, int layerIndex, int tileIndex, int tileset, int x, int y);

    ResourceManager& m_resourceManager;

    std::string m_tilesetDirectory;

    const int m_tileSize;

    /* I could replace m_mapLayers with m_map of type vector<vector<sf:Sprite>>
     * But this could be mistaken for a 2D array of tiles
     *
     * So this struct force to use the map as follows :
     * 		m_mapLayer[<layer index>].tiles[<tile index>]
     * instead of :
     * 		m_map[<layer index>][<tile index>]
     */
	struct TileMapLayer
	{
		std::vector<sf::Sprite> tiles;
	};

	std::vector<TileMapLayer> m_mapLayers;

	const TileMapData* m_mapData;

    std::map<int,std::shared_ptr<const sf::Texture>> m_tilesetTextureMap;

    sf::Texture m_transparentTile;
};

} // namespace mge

#endif // TILEMAP_HPP_
