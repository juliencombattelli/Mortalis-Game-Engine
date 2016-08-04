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

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include <memory>

namespace mge
{

class ResourceManager;

struct MapLayer
{
	std::shared_ptr<sf::Texture> tileset;
	std::vector<uint8_t> tiles;
	sf::VertexArray vertices;
};

struct TileMapData
{
	std::string mapName;
	sf::Vector2u tileSize;
	sf::Vector2u size;

	MapLayer layer1;
};

class TileMap : public sf::Drawable, public sf::Transformable
{
public:

	TileMap(ResourceManager& resourceManager);
	TileMap(const TileMap&) = delete;
	TileMap& operator=(const TileMap&)= delete;
    ~TileMap() = default;

    bool load(const std::string& mapName);

    sf::Vector2u getSizePixel() const { return { m_data.size.x * m_data.tileSize.x, m_data.size.y * m_data.tileSize.y}; }

private:

    bool loadFromFile(const std::string& mapName);
    bool loadFromMemory(const TileMapData& data);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

    ResourceManager& m_resourceManager;

    TileMapData m_data;
};

} // namespace mge

#endif // TILEMAP_HPP_
