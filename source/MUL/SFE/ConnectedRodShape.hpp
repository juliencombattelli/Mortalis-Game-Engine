//============================================================================
// Name        : ConnectedRodShape.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 10, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef CONNECTEDRODSHAPE_HPP_
#define CONNECTEDRODSHAPE_HPP_

#include <SFML/Graphics/Shape.hpp>

namespace mul { namespace sfe
{

class ConnectedRodShape : public sf::Shape
{
public :

    explicit ConnectedRodShape(float radius, float armLength, std::size_t pointCount = 60);

    float getRadius() const;
    float getLength() const;

    void setOriginTopLeft() { setOrigin(0,0); }
    void setOriginFirstArc() { setOrigin(m_radius,m_radius); }

    virtual std::size_t getPointCount() const override;

    virtual sf::Vector2f getPoint(std::size_t index) const override;

private :

    float m_radius;
    float m_armLength;

    std::size_t m_pointCount;
};

} // namespace sfe
} // namespace mul

#endif // CONNECTEDRODSHAPE_HPP_
