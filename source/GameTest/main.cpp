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
#include <MGE/Input/InputManager.hpp>
#include <stack>
#include <iostream>
#include <cmath>

int main()
{
	sf::RenderWindow window({800,600},"test");
	mge::InputManager input;

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

		input.update();

		if(input.isSelectedOnce(mge::Action::moveLeft))
			a.rotate(0,sign*20);
		else if(input.isSelectedOnce(mge::Action::moveDown))
			a.rotate(1,sign*20);
		else if(input.isSelectedOnce(mge::Action::moveRight))
			a.rotate(2,sign*20);
		else if(input.isSelectedOnce(mge::Action::accept))
			sign = -sign;

		window.clear();
		window.draw(a);
		window.display();
	}
}

/*
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
#include <MGE/Input/InputManager.hpp>
#include <iostream>

using namespace std;

int main()
{
	sf::RenderWindow window({800,600},"test");

	mge::InputManager mgr;

//	int ds4 = scanJoysticks(0x054C, 0x05C4);
//
//	if(ds4 < sf::Joystick::Count)
//	{
//		cout << "Joystick #0 connected" << endl;
//		cout << string(sf::Joystick::getIdentification(0).name) << endl;
//		cout << hex << sf::Joystick::getIdentification(0).vendorId << endl;
//		cout << sf::Joystick::getIdentification(0).productId << dec << endl;
//		unsigned int buttonCount = sf::Joystick::getButtonCount(0);
//		cout << "Joystick #0 have " << buttonCount << " buttons" << endl;
//	}
//	else
//		return 0;

	int j = 0;
	while(window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();
		}

		mgr.update();

		if(mgr.isSelectedOnce(mge::Action::moveUp))
		{
			j++;
			cout << "move Up #" << j << endl;
		}

//		cout << "X    : " << sf::Joystick::getAxisPosition(0,sf::Joystick::X) << endl;
//		cout << "Y    : " << sf::Joystick::getAxisPosition(0,sf::Joystick::Y) << endl;
//		cout << "Z    : " << sf::Joystick::getAxisPosition(0,sf::Joystick::Z) << endl;
//		cout << "R    : " << sf::Joystick::getAxisPosition(0,sf::Joystick::R) << endl;
//		cout << "U    : " << sf::Joystick::getAxisPosition(0,sf::Joystick::U) << endl;
//		cout << "V    : " << sf::Joystick::getAxisPosition(0,sf::Joystick::V) << endl;
//		cout << "PovX : " << sf::Joystick::getAxisPosition(0,sf::Joystick::PovX) << endl;
//		cout << "PovY : " << sf::Joystick::getAxisPosition(0,sf::Joystick::PovY) << endl;

		window.clear();
		window.display();
	}

	return 0;
}
*/

/*
#include <MGE/Core/Engine/Engine.hpp>

int main()
{
	mge::Engine engine;
    mge::Status status = engine.run();

    return static_cast<int>(status);
}*/
