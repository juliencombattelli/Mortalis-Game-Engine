//============================================================================
// Name        : SceneMap.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MortalisGameEngine project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <GameTest/Scenes/SceneMap.hpp>
#include <MGE/Resource/ResourceManager.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <GameTest/Maps/Maps.hpp>

namespace game
{

SceneMap::SceneMap(mge::ResourceManager& resourceManager) :
		m_map(resourceManager, mge::tilesetDirectory, mge::TileSize),
		m_actor1Texture("resources/Actor1.png", resourceManager)
{
    m_map.load(map0);

    m_heros.init(m_actor1Texture.getResource());

    m_view.setCenter(m_heros.getPosition().x+16, m_heros.getPosition().y+16);
    m_view.setViewport(sf::FloatRect(0,0,1.0f, 1.0f));
}

void SceneMap::handleEvent(sf::Event& event, const mge::Keyboard& keyboard)
{
    if (keyboard.isKeyPressed(mge::Action::accept))
        m_heros.run();
    else
        m_heros.walk();

    if (keyboard.isDKeyPressed(mge::Action::moveUp))
        m_heros.moveUp();
    if (keyboard.isDKeyPressed(mge::Action::moveDown))
        m_heros.moveDown();
    if (keyboard.isDKeyPressed(mge::Action::moveLeft))
        m_heros.moveLeft();
    if (keyboard.isDKeyPressed(mge::Action::moveRight))
        m_heros.moveRight();
}

void SceneMap::update(float elapsedTime)
{
    m_heros.animate(elapsedTime);
    updateView();
}

void SceneMap::draw(sf::RenderTarget& window)
{
	m_view.setSize(window.getSize().x, window.getSize().y);
    window.setView(m_view);

    window.draw(m_map);
    window.draw(m_heros);
}

void SceneMap::pause()
{

}

void SceneMap::resume()
{

}

void SceneMap::updateView()
{
    sf::Vector2f position;

    if(m_view.getSize().x > m_map.getSize().x)
        position.x = m_map.getSize().x/2;
    else if(m_heros.getPosition().x + 16 < m_view.getSize().x/2)
        position.x = m_view.getSize().x/2;
    else if(m_heros.getPosition().x + 16 > m_map.getSize().x - m_view.getSize().x/2)
        position.x = m_map.getSize().x - m_view.getSize().x/2;
    else
        position.x = m_heros.getPosition().x + 16;

    if(m_view.getSize().y > m_map.getSize().y)
        position.y = m_map.getSize().y/2;
    else if(m_heros.getPosition().y + 16 < m_view.getSize().y/2)
        position.y = m_view.getSize().y/2;
    else if(m_heros.getPosition().y + 16 > m_map.getSize().y - m_view.getSize().y/2)
        position.y = m_map.getSize().y - m_view.getSize().y/2;
    else
        position.y = m_heros.getPosition().y + 16;


    m_view.setCenter(position);
}

} // namespace game


