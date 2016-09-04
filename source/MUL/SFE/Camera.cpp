//============================================================================
// Name        : Camera.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : This file provide a player-follow camera
//============================================================================

#include <MUL/SFE/Camera.hpp>

namespace mul { namespace sfe
{

Camera::Camera(int tileSize) :
		m_halfTileSize(tileSize/2)
{

}

void Camera::update(const sf::Vector2f& playerPosition, const sf::Vector2f& mapSize)
{
    sf::Vector2f position;

    if(m_view.getSize().x > mapSize.x)
        position.x = mapSize.x/2;
    else if(playerPosition.x + m_halfTileSize < m_view.getSize().x/2)
        position.x = m_view.getSize().x/2;
    else if(playerPosition.x + m_halfTileSize > mapSize.x - m_view.getSize().x/2)
        position.x = mapSize.x - m_view.getSize().x/2;
    else
        position.x = playerPosition.x + m_halfTileSize;

    if(m_view.getSize().y > mapSize.y)
        position.y = mapSize.y/2;
    else if(playerPosition.y + m_halfTileSize < m_view.getSize().y/2)
        position.y = m_view.getSize().y/2;
    else if(playerPosition.y + m_halfTileSize > mapSize.y - m_view.getSize().y/2)
        position.y = mapSize.y - m_view.getSize().y/2;
    else
        position.y = playerPosition.y + m_halfTileSize;

    m_view.setCenter(position);
}

void Camera::setViewSize(float width, float height)
{
	m_view.setSize(width, height);
}

void Camera::setViewSize(const sf::Vector2f& size)
{
	m_view.setSize(size);
}

void Camera::adaptViewSizeToWindow(const sf::RenderTarget& window)
{
	m_view.setSize(sf::Vector2f(window.getSize()));
}

const sf::View& Camera::getView() const
{
	return m_view;
}

} // namespace sfe
} // namespace mul


