//============================================================================
// Name        : SceneMap.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <GameTest/Scenes/SceneMap.hpp>
#include <GameTest/Maps/Maps.hpp>
#include <MGE/Resource/ResourceManager.hpp>

#include <SFML/Window/Keyboard.hpp>


namespace game
{

SceneMap::SceneMap(mge::ResourceManager& resourceManager) :
		m_camera(mge::TileSize),
		m_map(resourceManager, mge::TilesetDirectory, mge::TileSize),
		m_actor1Texture("resources/Actor1.png", resourceManager)
{
    m_map.load(map0);

    m_heros.init(m_actor1Texture.get());

    mge::InputFileResource licenseFile("LICENSE.txt", resourceManager);
    std::cout << licenseFile->rdbuf() << std::endl;
	licenseFile->close();
}

void SceneMap::handleEvent(sf::Event& event, const mge::InputManager& keyboard)
{
    if (keyboard.isSelected(mge::Action::accept))
        m_heros.run();
    else
        m_heros.walk();

   /* if (keyboard.isDKeyPressed(mge::Action::moveUp))
        m_heros.moveUp();
    if (keyboard.isDKeyPressed(mge::Action::moveDown))
        m_heros.moveDown();
    if (keyboard.isDKeyPressed(mge::Action::moveLeft))
        m_heros.moveLeft();
    if (keyboard.isDKeyPressed(mge::Action::moveRight))
        m_heros.moveRight();*/
}

void SceneMap::update(float elapsedTime)
{
    m_heros.animate(elapsedTime);
    m_camera.update(m_heros.getPosition(), m_map.getSize());
}

void SceneMap::draw(sf::RenderTarget& window)
{
	m_camera.adaptViewSizeToWindow(window);
	window.setView(m_camera.getView());

    window.draw(m_map);
    window.draw(m_heros);
}

void SceneMap::pause()
{

}

void SceneMap::resume()
{

}

} // namespace game


