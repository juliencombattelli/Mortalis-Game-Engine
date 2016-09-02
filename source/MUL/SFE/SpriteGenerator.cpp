//============================================================================
// Name        : SpriteGenerator.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 27 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provides an utility class allowing the user to indexing
//               sprite in spritesheet using its number instead of its
//               coordinates
//============================================================================

#include "SpriteGenerator.hpp"

namespace mul { namespace sfe
{

SpriteGenerator::SpriteGenerator(const sf::Texture& spriteSheet, sf::Vector2u spriteNumber, sf::Vector2u spriteSize) :
	m_spriteSheet(&spriteSheet), m_spriteNumber(spriteNumber), m_spriteSize(spriteSize) {}

sf::Sprite SpriteGenerator::get(int spriteNumber) const
{
	int top  = spriteNumber / m_spriteNumber.x * m_spriteSize.y;
	int left = spriteNumber % m_spriteNumber.x * m_spriteSize.x;
	return sf::Sprite(*m_spriteSheet, sf::IntRect(left,top,m_spriteSize.x,m_spriteSize.y));
}

void SpriteGenerator::set(const sf::Texture& spriteSheet, sf::Vector2u spriteNumber, sf::Vector2u spriteSize)
{
	m_spriteSheet = &spriteSheet;
	m_spriteNumber = spriteNumber;
	m_spriteSize = spriteSize;
}

void SpriteGenerator::SpriteGenerator::setSpriteSheet(const sf::Texture& spriteSheet)
{
	m_spriteSheet = &spriteSheet;
}

void SpriteGenerator::setSpriteNumber(const sf::Vector2u& spriteNumber)
{
	m_spriteNumber = spriteNumber;
}

void SpriteGenerator::setSpriteSize(const sf::Vector2u& spriteSize)
{
	m_spriteSize = spriteSize;
}

} // namespace sfe
} // namespace mul


