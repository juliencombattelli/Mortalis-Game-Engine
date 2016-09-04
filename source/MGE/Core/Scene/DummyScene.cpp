//============================================================================
// Name        : DummyScene.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 2 juil. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#include <MGE/Core/Scene/DummyScene.hpp>

namespace mge
{

DummyScene::DummyScene(const ResourceManager& resourceManager) :
	m_font("resources/NotoSans-Regular.ttf", resourceManager),
	m_text("\nThis is a dummy scene.\nYou probably forget to set InitialScene typedef in MGE/Config/SceneConfig.hpp.",
			m_font.getResource(), 20)
{

}

DummyScene::~DummyScene()
{

}

void DummyScene::handleEvent(sf::Event& event, const Keyboard& keyboard)
{

}

void DummyScene::update(float elapsedTime)
{

}

void DummyScene::draw(sf::RenderTarget& window)
{
	window.draw(m_text);
}

void DummyScene::pause()
{

}

void DummyScene::resume()
{

}

} // namespace mge
