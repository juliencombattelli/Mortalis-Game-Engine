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

#include <GameTest/States/SceneMap.hpp>
#include <MGE/Resource/ResourceManager.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace game
{

SceneMap::SceneMap(mge::ResourceManager& resourceManager) :
		m_Actor1Texture("Actor1.png", resourceManager),
		mTileMap(resourceManager)
{
    /*if (!mTexture.loadFromFile(pictureFolder+"Heros1"+pictureExt))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
    }*/

    //mTexture.loadFromImage(mApp->getResourceManager().getResource("Heros1"));

    //mView.setSize(mRenderManager.DEFAULT_VIDEO_WIDTH, mRenderManager.DEFAULT_VIDEO_HEIGHT);
    mView.setCenter(mHeros.getPosition().x+16, mHeros.getPosition().y+16);
    mView.setViewport(sf::FloatRect(0,0,1.0f, 1.0f));

    //mTileMap.load("WorldMap");
    //mHeros.init(m_Actor1Texture.getResource());
}

void SceneMap::handleEvent(sf::Event& event, const mge::Keyboard& keyboard)
{
    /*if (keyboard.isKeyPressed(mge::Action::accept))
        mHeros.run();
    else
        mHeros.walk();

    if (keyboard.isDKeyPressed(mge::Action::moveUp))
        mHeros.moveUp();
    if (keyboard.isDKeyPressed(mge::Action::moveDown))
        mHeros.moveDown();
    if (keyboard.isDKeyPressed(mge::Action::moveLeft))
        mHeros.moveLeft();
    if (keyboard.isDKeyPressed(mge::Action::moveRight))
        mHeros.moveRight();*/
}

void SceneMap::update(float elapsedTime)
{
    //mHeros.animate(elapsedTime);
    updateView();
}

void SceneMap::draw(sf::RenderTarget& window)
{
	mView.setSize(window.getSize().x, window.getSize().y);
    window.setView(mView);
    //window.draw(mTileMap);
    window.draw(mHeros);
}

void SceneMap::pause()
{

}

void SceneMap::resume()
{

}

void SceneMap::updateView()
{
    /*sf::Vector2f position;

    if(mView.getSize().x > mTileMap.getSizeX_pix())
        position.x = mTileMap.getSizeX_pix()/2;
    else if(mHeros.getPosition().x + 16 < mView.getSize().x/2)
        position.x = mView.getSize().x/2;
    else if(mHeros.getPosition().x + 16 > mTileMap.getSizeX_pix() - mView.getSize().x/2)
        position.x = mTileMap.getSizeX_pix() - mView.getSize().x/2;
    else
        position.x = mHeros.getPosition().x + 16;

    if(mView.getSize().y > mTileMap.getSizeY_pix())
        position.y = mTileMap.getSizeY_pix()/2;
    else if(mHeros.getPosition().y + 16 < mView.getSize().y/2)
        position.y = mView.getSize().y/2;
    else if(mHeros.getPosition().y + 16 > mTileMap.getSizeY_pix() - mView.getSize().y/2)
        position.y = mTileMap.getSizeY_pix() - mView.getSize().y/2;
    else
        position.y = mHeros.getPosition().y + 16;


    mView.setCenter(position);*/
}

} // namespace game


