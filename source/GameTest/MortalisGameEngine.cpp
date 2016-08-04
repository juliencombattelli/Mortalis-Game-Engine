//============================================================================
// Name        : sfml_base.cpp
// Author      : Julien Combattelli
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
#include <MUL/SFE.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


namespace mge
{

enum class StatusType : sf::Int8
{
    StatusOpenGLInitFailed = -5,  ///< OpenGL initialization failed
    StatusAppMissingAsset  = -4,  ///< Application failed due to missing asset file
    StatusAppStackEmpty    = -3,  ///< Application States stack is empty
    StatusAppInitFailed    = -2,  ///< Application initialization failed
    StatusError            = -1,  ///< General error status response
    StatusNoError          =  0,  ///< General no error status response
    StatusAppOK            =  0,  ///< Application quit without error
    StatusOK               =  1   ///< OK status response
};

class Engine
{
public:
	Engine() :
		//m_window(sf::VideoMode::getFullscreenModes()[0], "SFML works!", sf::Style::Fullscreen),
		m_window(sf::VideoMode(800,600), "SFML works!"),
		m_isRunning(false), m_exitStatus(StatusType::StatusNoError)
	{

	}

	bool isRunning() const
	{
		return m_isRunning;
	}
	void quit(StatusType exitStatus)
	{
	    m_exitStatus = exitStatus;
	    m_isRunning = false;
	}
	void openErrorWindow()
	{
		m_window.close();
		m_window.create(sf::VideoMode(200,100), "Error", sf::Style::Close);
		m_isRunning = false;
		while(m_window.isOpen())
		{
			sf::Event event;
			while(m_window.pollEvent(event))
			{
				if(event.type == sf::Event::Closed or mul::sfe::Keyboard::areKeyPressed({sf::Keyboard::LAlt, sf::Keyboard::F4}))
				{
					m_window.close();
					quit(StatusType::StatusError);
				}
			}
			m_window.clear();
			m_window.display();
		}
	}
	StatusType run()
	{
		m_isRunning = true;
	    gameLoop();
	    cleanup();
	    return m_exitStatus;
	}

protected:

	void init()
	{

	}
	void handleEvent()
	{
		sf::Event event;
		while(m_window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed or mul::sfe::Keyboard::areKeyPressed({sf::Keyboard::LAlt, sf::Keyboard::F4}))
			{
				quit(StatusType::StatusAppOK);
			}
			else if(event.type == sf::Event::GainedFocus)
			{
			}
			else if(event.type == sf::Event::LostFocus)
			{
			}
			else if(event.type == sf::Event::Resized)
			{
			}
		}
	}
	void gameLoop()
	{
		sf::Texture texture;
		if(not texture.loadFromFile("Actor1.png"))
			exit(1);
		mul::sfe::SpriteGenerator sg(texture, {12,8}, {32,32});
		mul::sfe::AnimatedSprite<std::string> as(true, true);
		as.setPosition(400, 300);

		as.addFrame("down",  sg.get(1), sf::seconds(0.25));
		as.addFrame("down",  sg.get(2), sf::seconds(0.25));
		as.addFrame("down",  sg.get(1), sf::seconds(0.25));
		as.addFrame("down",  sg.get(0), sf::seconds(0.25));

		as.addFrame("left",  sg.get(13), sf::seconds(0.25));
		as.addFrame("left",  sg.get(14), sf::seconds(0.25));
		as.addFrame("left",  sg.get(13), sf::seconds(0.25));
		as.addFrame("left",  sg.get(12), sf::seconds(0.25));

		as.addFrame("right", sg.get(25), sf::seconds(0.25));
		as.addFrame("right", sg.get(26), sf::seconds(0.25));
		as.addFrame("right", sg.get(25), sf::seconds(0.25));
		as.addFrame("right", sg.get(24), sf::seconds(0.25));

		as.addFrame("up",    sg.get(37), sf::seconds(0.25));
		as.addFrame("up",    sg.get(38), sf::seconds(0.25));
		as.addFrame("up",    sg.get(37), sf::seconds(0.25));
		as.addFrame("up",    sg.get(36), sf::seconds(0.25));

		as.play("down");

		sf::Clock frameClock;
	    while(m_isRunning)
	    {
	    	handleEvent();

	    	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	    		openErrorWindow();
	    	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	        	as.play("up");
	        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	        	as.play("down");
	        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	        	as.play("left");
	        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	        	as.play("right");
	        else
	        	as.stop();

	        as.update(frameClock.restart());

	        m_window.clear();
	        m_window.draw(as);
	        m_window.display();
	    }
	}
	void cleanup()
	{

	}

	sf::RenderWindow m_window;
	bool m_isRunning;
	StatusType m_exitStatus;
};

}

int main()
{
	mge::Engine e;
    mge::StatusType status = e.run();

    return static_cast<int>(status);
}*/
