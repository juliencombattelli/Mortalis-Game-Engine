//============================================================================
// Name        : DelayedFrame.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provide a temporary frame class as an extension of the
//               SFML library
//============================================================================

#include "DelayedFrame.hpp"

namespace mul { namespace sfe
{

DelayedFrame::DelayedFrame(const sf::Sprite& sprite, const sf::Time& duration, bool isValid) :
	Frame(sprite, duration)
{
	m_isValid = isValid;
}

DelayedFrame::~DelayedFrame()
{

}

bool DelayedFrame::update(sf::Time deltaTime)
{
	if(m_isValid)
	{
		m_currentTime += deltaTime;
		if(m_currentTime >= m_frame.second)
		{
			m_currentTime = sf::Time::Zero;
			m_isValid = false;
		}
	}
	return not m_isValid;
}

void DelayedFrame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(m_isValid)
		target.draw(m_frame.first, states);
}

} // namespace sfe
} // namespace mul
