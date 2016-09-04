//============================================================================
// Name        : Camera.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : This file provide a player-follow camera
//============================================================================

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace mul { namespace sfe
{

class Camera
{
public:

	Camera(int tileSize);

	void update(const sf::Vector2f& playerPosition, const sf::Vector2f& mapSize);

	void setViewSize(float width, float height);

	void setViewSize(const sf::Vector2f& size);

	void adaptViewSizeToWindow(const sf::RenderTarget& window);

	const sf::View& getView() const;

private:

	sf::View m_view;
	int m_halfTileSize;
};

} // namespace sfe
} // namespace mul

#endif // CAMERA_HPP_
