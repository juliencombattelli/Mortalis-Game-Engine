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
#include <MGE/Input/Input.hpp>
#include <stack>
#include <iostream>
#include <cmath>

static const float to_rad = 3.14159265359f / 180.f;

float distance(const sf::Vector2f& a, const sf::Vector2f& b)
{
	return std::sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

class RoboticArm : public sf::Drawable
{
public:

	RoboticArm(unsigned segmentNumber, float length) :
		m_segments(segmentNumber,mul::sfe::ConnectedRodShape(length/10,length)),
		m_linkPoints(segmentNumber, sf::CircleShape(4)),
		m_length(length)
	{
		for(unsigned i = 0 ; i < m_segments.size() ; i++)
		{
			m_segments[i].setPosition(length*i+100,100);
			m_linkPoints[i].setPosition(m_segments[i].getPosition() - sf::Vector2f(4,4));
		}
	}

	void setFillColor(std::vector<sf::Color> colors)
	{
		for(unsigned i = 0 ; i < m_segments.size() and i < colors.size(); i++)
			m_segments[i].setFillColor(colors[i]);
	}

	void rotate(unsigned segment, float angle)
	{
		if(segment >= m_segments.size())
			throw std::out_of_range("RoboticArm::rotate : receive out of range segment.");

		auto origin = m_segments[segment].getPosition();

		m_segments[segment].rotate(angle);

		for(unsigned i = segment+1 ; i < m_segments.size() ; i++)
		{
			auto vectSegmentIOrigin = m_segments[i].getPosition() - origin;

			m_segments[i].setPosition(
				cos(angle*to_rad)*vectSegmentIOrigin.x - sin(angle*to_rad)*vectSegmentIOrigin.y + origin.x,
			    sin(angle*to_rad)*vectSegmentIOrigin.x + cos(angle*to_rad)*vectSegmentIOrigin.y + origin.y);

			m_linkPoints[i].setPosition(m_segments[i].getPosition() - sf::Vector2f(4,4));

			m_segments[i].rotate(angle);
		}
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for(auto& segment : m_segments)
			target.draw(segment, states);
		for(auto& point : m_linkPoints)
			target.draw(point, states);
	}

private:

	std::vector<mul::sfe::ConnectedRodShape> m_segments;
	std::vector<sf::CircleShape> m_linkPoints;
	float m_length;
};

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
