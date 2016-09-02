//============================================================================
// Name        : FpsCalculator.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 26, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef FPSCALCULATOR_HPP_
#define FPSCALCULATOR_HPP_

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>

#include <string>
#include <cmath>

namespace mul { namespace sfe
{

class FpsCalculator : public sf::Drawable
{
public:

	FpsCalculator(const std::string& font, float displayRefreshFrequency) :
		m_displayRefreshRateSecond(1.f / displayRefreshFrequency),
		m_lastValue(0)
	{
		if(not m_font.loadFromFile(font))
			throw std::runtime_error("Failed to load font \"" + font + "\"");
		m_label.setFont(m_font);
	}

	void update()
	{
		float fps = 1.f / m_fpsClock.restart().asSeconds();

		if(m_displayClock.getElapsedTime().asSeconds() > m_displayRefreshRateSecond)
		{
			m_lastValue = static_cast<int>(std::round(fps));
			m_displayClock.restart();
		}

		m_label.setString(std::to_string(m_lastValue));
		m_label.setFillColor(sf::Color::White);
	}

protected:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(m_label, states);
	}

	sf::Font m_font;
	sf::Text m_label;
	sf::Clock m_fpsClock;
	sf::Clock m_displayClock;
	float m_displayRefreshRateSecond;
	int m_lastValue;
};

} // namespace sfe
} // namespace mul

#endif // FPSCALCULATOR_HPP_
