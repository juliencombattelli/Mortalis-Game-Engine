//============================================================================
// Name        : SimuScene.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 9, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================


#include <GameTest/Scenes/SimuScene.hpp>
#include <GameTest/Maps/Maps.hpp>
#include <MGE/Resource/ResourceManager.hpp>

#include <SFML/Window/Keyboard.hpp>

#include <cmath>

namespace game
{

SimuScene::SimuScene(mge::ResourceManager& resourceManager) :
		arm(2,10,50,{100,100})
{
	arm.rotate(1,45);
	arm.rotate(0,45);
}

void SimuScene::handleEvent(sf::Event& event, const mge::Keyboard& keyboard)
{

}

void SimuScene::update(float elapsedTime)
{

}

void SimuScene::draw(sf::RenderTarget& window)
{
	window.draw(arm);
}

void SimuScene::pause()
{

}

void SimuScene::resume()
{

}

} // namespace game



