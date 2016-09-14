//============================================================================
// Name        : main.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Mar 1, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : Entry point of the program
//============================================================================

#include <SFML/Graphics.hpp>
#include <MUL/SFE/ConnectedRodShape.hpp>
#include <MUL/RoboticArm.hpp>
#include <MGE/Input/Input.hpp>
#include <stack>
#include <iostream>
#include <cmath>

int main()
{
	sf::RenderWindow window({800,600},"test");
	mge::Keyboard keyboard;

	sf::RectangleShape base({100,100});

	RoboticArm a(3,200);
	a.setFillColor({sf::Color::Red, sf::Color::Green, sf::Color::Blue});

	int sign = 1;

	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		keyboard.update();

		if(keyboard.isKeyPressedOnce(mge::Action::moveLeft))
			a.rotate(0,sign*20);
		else if(keyboard.isKeyPressedOnce(mge::Action::moveDown))
			a.rotate(1,sign*20);
		else if(keyboard.isKeyPressedOnce(mge::Action::moveRight))
			a.rotate(2,sign*20);
		else if(keyboard.isKeyPressedOnce(mge::Action::accept))
			sign = -sign;

		window.clear();
		window.draw(a);
		window.display();
	}
}

/*
#include <MGE/Core/Engine/Engine.hpp>

int main()
{
	mge::Engine engine;
    mge::Status status = engine.run();

    return static_cast<int>(status);
}*/
