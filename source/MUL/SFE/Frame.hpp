//============================================================================
// Name        : Frame.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provide a frame class as an extension of the SFML library
//============================================================================

#ifndef FRAME_HPP_
#define FRAME_HPP_

#if __cplusplus < 201103L
  #error This library needs at least a C++11 compliant compiler
#endif

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace mul { namespace sfe
{

class Frame : public sf::Drawable
{
public:
	Frame(const sf::Sprite& sprite, const sf::Time& duration);

	virtual ~Frame();

	sf::Sprite& sprite();
	const sf::Sprite& sprite() const;

	sf::Time& duration();
	const sf::Time& duration() const;

	bool isValid() const;
	void validate();

	virtual bool update(sf::Time deltaTime);

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	std::pair<sf::Sprite, sf::Time> m_frame;
	sf::Time m_currentTime;
	bool m_isValid;
};

} // namespace sfe
} // namespace mul

#endif // FRAME_HPP_
