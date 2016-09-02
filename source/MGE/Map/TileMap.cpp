//============================================================================
// Name        : TileMap.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MortalisGameEngine project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================
/*
#include <MGE/Map/TileMap.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace mge
{

TileMap::TileMap(ResourceManager& resourceManager) :
	m_resourceManager(resourceManager)
{

}

bool TileMap::load(const std::string& mapName)
{
    if(not loadFromFile(mapName))
    	return false;

    m_data.layer1.vertices.setPrimitiveType(sf::Quads);
    m_data.layer1.vertices.resize(m_data.size.x * m_data.size.y * 4);

    for (uint32_t i = 0; i < m_data.size.x; ++i)
        for (uint32_t j = 0; j < m_data.size.y; ++j)
        {
            uint32_t tileNumber = static_cast<uint32_t>(m_data.layer1.tiles[i + j * m_data.size.x]);

            uint32_t tu = tileNumber % m_data.size.x;
            uint32_t tv = tileNumber / m_data.size.x;

            sf::Vertex* quad = &m_data.layer1.vertices[(i + j * m_data.size.x) * 4];

            if(quad == nullptr)
            	return false;

            quad[0].position = sf::Vector2f(float(i * m_data.tileSize.x), float(j * m_data.tileSize.y));
            quad[1].position = sf::Vector2f(float((i + 1) * m_data.tileSize.x), float(j * m_data.tileSize.y));
            quad[2].position = sf::Vector2f(float((i + 1) * m_data.tileSize.x), float((j + 1) * m_data.tileSize.y));
            quad[3].position = sf::Vector2f(float(i * m_data.tileSize.x), float((j + 1) * m_data.tileSize.y));

            quad[0].texCoords = sf::Vector2f(float(tu * m_data.tileSize.x), float(tv * m_data.tileSize.y));
            quad[1].texCoords = sf::Vector2f(float((tu + 1) * m_data.tileSize.x), float(tv * m_data.tileSize.y));
            quad[2].texCoords = sf::Vector2f(float((tu + 1) * m_data.tileSize.x), float((tv + 1) * m_data.tileSize.y));
            quad[3].texCoords = sf::Vector2f(float(tu * m_data.tileSize.x), float((tv + 1) * m_data.tileSize.y));
        }

    return true;
}

bool TileMap::loadFromFile(const std::string& mapName)
{*/
    /*utility::ibfstream file( mapFolder + mapName + mapExt );

    if(not file.isOpen())
        return false;

    size_t fileLength = file.getFileLength();
    uint8_t* buffer = new uint8_t[fileLength];
    size_t position = 0;

    file.read(buffer, fileLength);

    m_data.mapName = utility::readString(buffer, 0, 20);
    position += m_data.mapName.size()+1;

    std::string tilesheetName = utility::readString(buffer, position, 20);
    m_data.layer1.tileset = &m_data.resourceManager.getTextureResource(tilesheetName);
    position += tilesheetName.size()+1;

    m_data.tileSize = utility::read4Byte(buffer, position);
    position += 4;

    mSize.x = utility::read4Byte(buffer, position);
    position += 4;

    mSize.y = utility::read4Byte(buffer, position);
    position += 4;

    mTilesLayer1.resize(mSize.x*mSize.y);
    mTilesLayer1.assign(mSize.x*mSize.y, 0x00);

    delete[] buffer;

    file.close();*//*

    return true;
}

bool TileMap::loadFromMemory(const TileMapData& data)
{
	m_data = data;
    return true;
}

void TileMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    states.texture = m_data.layer1.tileset.get();

    target.draw(m_data.layer1.vertices, states);
}

} // namespace mge*/
