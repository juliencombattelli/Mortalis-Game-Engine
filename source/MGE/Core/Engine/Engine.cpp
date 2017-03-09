//============================================================================
// Name        : Engine.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 2 juil. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <MGE/Core/Engine/Engine.hpp>
#include <MGE/Core/Event/Event.hpp>
#include <MGE/Resource/Resource.hpp>
#include <MUL/SFE/Keyboard.hpp>
#include <SFML/Graphics.hpp>

namespace mge
{

Engine::Engine() :
	m_resourceManager(),
    m_isRunning(false),
	m_exitStatus(Status::StatusNoError)
{

}

Engine::~Engine()
{

}

void Engine::quit(mul::Sender& sender, const mul::Event& event)
{
	const QuitEvent* quitEvent = static_cast<const QuitEvent*>(&event);
	quit(quitEvent->exitStatus);
}

void Engine::quit(Status status)
{
	m_exitStatus = status;
	m_isRunning = false;
	if(m_exitStatus.isError())
		openErrorWindow(m_exitStatus, "An error occurred");
}

Status Engine::run()
{
	m_isRunning = true;

	try
	{
		init();

		gameLoop();

		cleanup();
	}
	catch(const std::exception& e)
	{
		openErrorWindow(m_exitStatus, e.what());
	}
	catch(...)
	{
		openErrorWindow(m_exitStatus, "An unknown error occured");
	}

    m_isRunning = false;

    return m_exitStatus;
}

void Engine::openErrorWindow(Status status, const std::string& errorMessage)
{
	m_window.close();
	m_window.create(sf::VideoMode(600,100), "Error", sf::Style::Close);
	m_isRunning = false;
	FontResource font("resources/NotoSans-Regular.ttf",m_resourceManager);
	sf::Text errorText(errorMessage, font.get(), 20);
	while(m_window.isOpen())
	{
		sf::Event event;
		while(m_window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed or
					mul::sfe::Keyboard::areKeyPressed({sf::Keyboard::LAlt, sf::Keyboard::F4}))
			{
				m_window.close();
			}
		}
		m_window.clear();
		m_window.draw(errorText);
		m_window.display();
	}
}

void Engine::init()
{
	/*m_resourceManager.registerHolder<TextureHolder>();
	m_resourceManager.registerHolder<FontHolder>();
	m_resourceManager.registerHolder<InputFileHolder>();*/

	m_sceneManager.init(m_resourceManager);

    //mRendererManager.init();

	m_window.create(sf::VideoMode(800,600), "SFML !");

	// TODO : test on Windows
	/*sf::Image icon;
	if(not icon.loadFromFile("resources/dragon-red.png"))
		std::cout << "error loading icon" << std::endl;
	m_window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());*/
	//m_window.setIcon(gimp_image.width,  gimp_image.height,  gimp_image.pixel_data);
	m_inputManager.init();
}

void Engine::handleEvent(Scene& scene)
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed or
				mul::sfe::Keyboard::areKeyPressed({sf::Keyboard::LAlt, sf::Keyboard::F4}))
        {
            quit(Status::StatusUserQuit);
        }

        else if(event.type == sf::Event::GainedFocus)
        {
            scene.resume();
        }

        else if(event.type == sf::Event::LostFocus)
        {
            scene.pause();
        }

        else if(event.type == sf::Event::Resized)
        {

        }
    }

    scene.handleEvent(event, m_inputManager);
}

void Engine::gameLoop()
{
    sf::Clock frameClock;

    if(m_sceneManager.isEmpty())
        quit(Status::StatusAppInitFailed);

    while(isRunning() and not(m_sceneManager.isEmpty()) and m_window.isOpen())
    {
        Scene& scene = m_sceneManager.getActiveState();

		m_inputManager.update();

		handleEvent(scene);

		scene.update(frameClock.restart().asSeconds());

		m_window.clear();

		scene.draw(m_window);

		m_window.display();
    }
}

void Engine::cleanup()
{
    /*mRendererManager.cleanup()
    {
        if(mWindow.isOpen())
        {
            mWindow.setMouseCursorVisible(true);
            mWindow.close();
        }
    }
    mStateManager.cleanup();*/
}

} // namespace mge
