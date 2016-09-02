//============================================================================
// Name        : SpriteGenerator.hpp
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

#ifndef SPRITEGENERATOR_HPP_
#define SPRITEGENERATOR_HPP_

#include <SFML/Graphics/Sprite.hpp>

namespace mul { namespace sfe
{

class SpriteGenerator
{
public:
	SpriteGenerator(const sf::Texture& spriteSheet, sf::Vector2u spriteNumber, sf::Vector2u spriteSize);

	sf::Sprite get(int spriteNumber) const;

	void set(const sf::Texture& spriteSheet, sf::Vector2u spriteNumber, sf::Vector2u spriteSize);

	void setSpriteSheet(const sf::Texture& spriteSheet);

	void setSpriteNumber(const sf::Vector2u& spriteNumber);

	void setSpriteSize(const sf::Vector2u& spriteSize);

protected:
	const sf::Texture* m_spriteSheet;
	sf::Vector2u m_spriteNumber;
	sf::Vector2u m_spriteSize;
};

} // namespace sfe
} // namespace mul

#endif // SPRITEGENERATOR_HPP_
