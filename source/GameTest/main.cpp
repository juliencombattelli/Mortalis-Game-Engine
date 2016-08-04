/*
///////////////////////////////////////////////////////////////////////////////////////////////////
// Animated Sprite test
///////////////////////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Global.hpp"
#include "HerosSprite.hpp"
#include "TileMapDrawer.hpp"

int main()
{
    sf::Vector2f screenDimensions(800,600);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");
    window.setFramerateLimit(100);

    sf::Texture texture;
    if (!texture.loadFromFile(pictureFolder+"Heros1"+pictureExt))
    {
        std::cout << "Failed to load player spritesheet!" << std::endl;
        return 1;
    }

    //sf::View view;

    //rpg::TileMapDrawer tileMap;
    tileMap.load("WorldMap");

    //rpg::HerosSprite heros(texture, view, tileMap);

    view.setSize(screenDimensions);
    view.setCenter(heros.getPosition().x+16, heros.getPosition().y+16);
    view.setViewport(sf::FloatRect(0,0,1.0f, 1.0f));

    sf::Clock frameClock;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            heros.run();
        else
            heros.walk();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
             heros.moveUp();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            heros.moveDown();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            heros.moveLeft();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            heros.moveRight();


        sf::Time frameTime = frameClock.restart();
        heros.animate(frameTime.asSeconds());

        window.clear();
        window.setView(view);
        window.draw(tileMap);
        window.draw(heros);

        window.display();
    }

    return 0;
}
*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// TileMap test
///////////////////////////////////////////////////////////////////////////////////////////////////
/*#include "TileLoader.hpp"
#include "StaticTiledMap.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

class ExampleLoader : public TileLoader
{
public:
    ExampleLoader(void)
    {
        m_mapdata.sizeX=100;
        m_mapdata.sizeY=100;
        m_mapdata.textureName=pictureFolder+"World"+pictureExt;//a simple 32x32 seamless image of brick
    }
    virtual void appendTile(int gx,int gy,sf::VertexArray& garr)
    {
        sf::Vertex ver;
        ver.position=sf::Vector2f(gx*32.f,gy*32.f);
        ver.texCoords=sf::Vector2f(0.f,0.f);
        garr.append(ver);

        ver.position=sf::Vector2f(gx*32.f+32.f,gy*32.f);
        ver.texCoords=sf::Vector2f(32.f,0.f);
        garr.append(ver);

        ver.position=sf::Vector2f(gx*32.f+32.f,gy*32.f+32.f);
        ver.texCoords=sf::Vector2f(32.f,32.f);
        garr.append(ver);

        ver.position=sf::Vector2f(gx*32.f,gy*32.f+32.f);
        ver.texCoords=sf::Vector2f(0.f,32.f);
        garr.append(ver);
    }
};

int main(int argc, char* argv[])
{
    sf::RenderWindow app(sf::VideoMode(600,600),"test Tile map");
    app.setVerticalSyncEnabled(true);
    sf::View cam=app.getDefaultView();

    StaticTiledMap testmap;
    ExampleLoader example;
    testmap.LoadFrom(&example);
    while(app.isOpen())
    {
        sf::Event eve;
        while(app.pollEvent(eve))
            if(eve.type==sf::Event::Closed)
                app.close();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
            cam.zoom(1.05f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
            cam.zoom(0.95f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            cam.move(0.f,-10.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            cam.move(-10.f,0.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            cam.move(0.f,10.f);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            cam.move(10.f,0.f);

        app.setView(cam);
        app.clear();
        app.draw(testmap);
        app.display();
    }
}*/

///////////////////////////////////////////////////////////////////////////////////////////////////
// RPG main
///////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <MGE/Core/Engine/Engine.hpp>
#include <MUL/SFE.hpp>

int main()
{
	mge::Engine engine;
    mge::Status status = engine.run();

    return static_cast<int>(status);
}

