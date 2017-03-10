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

#include <GameTest/Sprites/RobotArm.hpp>

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace std;

namespace game
{

class SimuScene : public mge::Scene
{
public:
	SimuScene(mge::ResourceManager& resourceManager);
    virtual ~SimuScene() = default;

    virtual void handleEvent(sf::Event& event, const mge::InputManager& input) final;
    virtual void update(float elapsedTime) final;
    virtual void draw(sf::RenderTarget& window) final;

    virtual void pause() final;
    virtual void resume() final;

private:

	RobotArm arm;

};

} // namespace game



#endif // SIMUSCENE_HPP_
