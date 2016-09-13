//============================================================================
// Name        : SimuScene.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 9, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef SIMUSCENE_HPP_
#define SIMUSCENE_HPP_

#include <MGE/Core/Scene/Scene.hpp>
#include <MGE/Config/MapConfig.hpp>
#include <MGE/Resource/Resource.hpp>

#include <MUL/SFE/ConnectedRodShape.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

namespace game
{

class Arm
{
public:
	mul::sfe::ConnectedRodShape shape;
	sf::Transform transform;

	Arm(int radius, int length) : shape(radius,length) {}
};

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

class SimuScene : public mge::Scene
{
public:
	SimuScene(mge::ResourceManager& resourceManager);
    virtual ~SimuScene() = default;

    virtual void handleEvent(sf::Event& event, const mge::Keyboard& keyboard) final;
    virtual void update(float elapsedTime) final;
    virtual void draw(sf::RenderTarget& window) final;

    virtual void pause() final;
    virtual void resume() final;

private:

	RobotArm arm;

};

} // namespace game



#endif // SIMUSCENE_HPP_
