//============================================================================
// Name        : ConnectedRodShape.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 10, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <MUL/SFE/ConnectedRodShape.hpp>

#include <cmath>

namespace mul { namespace sfe
{

ConnectedRodShape::ConnectedRodShape(float radius, float armLength, std::size_t pointCount) :
	m_radius(radius), m_armLength(armLength), m_pointCount(pointCount)
{
	update();
}

float ConnectedRodShape::getRadius() const
{
	return m_radius;
}

float ConnectedRodShape::getLength() const
{
	return m_armLength;
}

std::size_t ConnectedRodShape::getPointCount() const
{
	return m_pointCount;
}

sf::Vector2f ConnectedRodShape::getPoint(std::size_t index) const
{
	static const float pi = 3.141592654f;
	static const unsigned int N = m_pointCount;
	static const unsigned int halfN = N/2;
	static const float anglePerPoint = (5.f*pi/3.f) / (halfN-1); // 300° / ( n/2 - 1)
	static const float firstArcOffsetAngle = pi/6.f;
	static const float secondArcOffsetAngle = pi/6.f + pi;

	sf::Vector2f result;

	if(0 <= index and index < halfN)
	{
		float angle = index * anglePerPoint + firstArcOffsetAngle;
		result.x = m_radius * std::cos(angle);
		result.y = m_radius * std::sin(angle);
	}
	else if(halfN <= index and index < N)
	{
		float angle = (index-halfN) * anglePerPoint + secondArcOffsetAngle;
		result.x = m_radius*cos(angle) + m_armLength;
		result.y = m_radius*sin(angle);
	}

	return result;
}

} // namespace sfe
} // namespace mul


