//============================================================================
// Name        : Frame.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provide a frame class as an extension of the SFML library
//============================================================================

#include "Frame.hpp"

namespace mul { namespace sfe
{

Frame::Frame(const sf::Sprite& sprite, const sf::Time& duration) :
	m_frame(sprite, duration), m_currentTime(sf::Time::Zero), m_isValid(true)
{

}

Frame::~Frame()
{

}

sf::Sprite& Frame::sprite()
{
	return m_frame.first;
}

const sf::Sprite& Frame::sprite() const
{
	return m_frame.first;
}

sf::Time& Frame::duration()
{
	return m_frame.second;
}

const sf::Time& Frame::duration() const
{
	return m_frame.second;
}

bool Frame::isValid() const
{
	return m_isValid;
}

void Frame::validate()
{
	m_currentTime = sf::Time::Zero;
	m_isValid = true;
}

bool Frame::update(sf::Time deltaTime)
{
	m_currentTime += deltaTime;
	if(m_currentTime >= m_frame.second)
	{
		m_currentTime = sf::Time::Zero;
		return true;
	}
	return false;
}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_frame.first, states);
}

} // namespace sfe
} // namespace mul
