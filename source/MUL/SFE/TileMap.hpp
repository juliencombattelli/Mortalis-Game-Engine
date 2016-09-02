//============================================================================
// Name        : TileMap.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Aug 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef TILEMAP_HPP_
#define TILEMAP_HPP_

#include <MUL/SFE/AutotilerVXAce.hpp>

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

#include <memory>
#include <map>
#include <vector>
#include <array>

namespace mul { namespace sfe
{

struct MapData
{
	std::string name;
	int row;
	int column;
	int tileSize;
	std::vector<int> tiles;
};

/*
 * This TileMap class works very well with RPG Maker VXAce tilesets.
 * For others, it might needs some adjustments.
 *
 * TODO add support for non-autotile tilesets;
 */
class TileMap : public sf::Drawable
{
public:

	TileMap(int tileSize);

	void addTileset(int id, const sf::Texture& tileset);

	void addAutotileset(int id, const sf::Texture& tileset);

	void loadFromMapData(MapData& map);

	sf::Vector2f getSize() const;

protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	struct MapInfo
	{
		MapInfo(int size) : tileSize(size) {}
		struct TileMapLayer
		{
			std::vector<sf::Sprite> tiles;
		};

		std::string name;
		sf::Vector2i size;
		const int tileSize;
		std::vector<TileMapLayer> layers;
	};

	struct TilesetInfo
	{
		std::shared_ptr<const sf::Texture> tileset;
		bool isAutotile;
	};

	MapInfo m_map;

	std::map<int,TilesetInfo> m_tilesets;

	sf::Texture m_transparentTile;
};

} // namespace sfe
} // namespace mul

#endif // TILEMAP_HPP_
