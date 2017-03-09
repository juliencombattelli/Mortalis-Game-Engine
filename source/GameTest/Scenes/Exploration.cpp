#include <GameTest/Scenes/Exploration.hpp>
#include <MGE/Resource/ResourceManager.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace rpg
{

Exploration::Exploration(mge::ResourceManager& resourceManager) :
		m_Actor1Texture("Actor1.png", resourceManager)/*,
		mTileMap(resourceManager)*/
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

Exploration::~Exploration()
{

}

void Exploration::handleEvent(sf::Event& event, const mge::InputManager& keyboard)
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

void Exploration::update(float elapsedTime)
{
    //mHeros.animate(elapsedTime);
    updateView();
}

void Exploration::draw(sf::RenderTarget& window)
{
	mView.setSize(window.getSize().x, window.getSize().y);
    window.setView(mView);
    //window.draw(mTileMap);
    window.draw(mHeros);
}

void Exploration::pause()
{

}

void Exploration::resume()
{

}

void rpg::Exploration::updateView()
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

}
