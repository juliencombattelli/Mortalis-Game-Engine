//============================================================================
// Name        : DummyScene.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 2 juil. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef DUMMYSCENE_HPP_
#define DUMMYSCENE_HPP_

#include <MGE/Core/Scene/Scene.hpp>
#include <MGE/Resource/Resource.hpp>
#include <SFML/Graphics/Text.hpp>

namespace mge
{

class DummyScene : public Scene
{
public:

	DummyScene(ResourceManager& resourceManager);
	virtual ~DummyScene();

	virtual void handleEvent(sf::Event& event, const InputManager& input) final;
	virtual void update(float elapsedTime) final;
	virtual void draw(sf::RenderTarget& window) final;

	virtual void pause() final;
	virtual void resume() final;

	static constexpr auto DummyText = "\nThis is a dummy scene.\nYou probably forget to set InitialScene typedef in MGE/Config/SceneConfig.hpp.";
protected:

	FontResource m_font;
	sf::Text m_text;
};

} // namespace mge

#endif // DUMMYSCENE_HPP_
