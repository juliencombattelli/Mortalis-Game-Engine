/*
 * RobotArm.hpp
 *
 *  Created on: 10 mars 2017
 *      Author: JulienCombattelli
 */

#ifndef GAMETEST_SPRITES_ROBOTARM_HPP_
#define GAMETEST_SPRITES_ROBOTARM_HPP_

#include <GameTest/Physics/Arm.hpp>

namespace game
{

class RobotArm : public sf::Drawable
{
public:

	RobotArm(int armNumber, int revoluteRadius, int armLength, const sf::Vector2f& position) :
		armAngle(0.f)
	{
		for(int i = 0 ; i < armNumber ; i++)
		{
			m_arms.emplace_back(revoluteRadius, armLength);
			m_arms.back().shape.setPosition(position.x + armLength*i, position.y);
		}
	}

	/*void setGlobalPosition(const sf::Vector2f& position)
	{
		for(unsigned i = 0 ; i < m_arms.size() ; i++)
		{
			m_arms[i].shape.setPosition(position);
		}
	}*/

	void rotate(int arm, float angle)
	{
		sf::Vector2f center = m_arms[arm].transform.transformPoint(m_arms[arm].shape.getPosition());

		for(unsigned i = arm ; i < m_arms.size() ; i++)
		{
			m_arms[i].transform.rotate(angle, center);
		}
	}

private:

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		for(auto& arm : m_arms)
		{
			target.draw(arm.shape,arm.transform);
		}
	}

	std::vector<Arm> m_arms;

	float armAngle;
};

} // namespace mge

#endif /* GAMETEST_SPRITES_ROBOTARM_HPP_ */
