//============================================================================
// Name        : DummyScene.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 2 juil. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MortalisGameEngine project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef DUMMYSCENE_HPP_
#define DUMMYSCENE_HPP_

#include <MGE/Core/Scene/Scene.hpp>
#include <MGE/Resource/TemplateResource.hpp>
#include <SFML/Graphics/Text.hpp>

namespace mge
{

class DummyScene : public Scene
{
public:

	DummyScene(const ResourceManager& resourceManager);
	virtual ~DummyScene();

	virtual void handleEvent(sf::Event& event, const Keyboard& keyboard) final;
	virtual void update(float elapsedTime) final;
	virtual void draw(sf::RenderTarget& window) final;

	virtual void pause() final;
	virtual void resume() final;

protected:

	FontResource m_font;
	sf::Text m_text;
};

} // namespace mge

#endif // DUMMYSCENE_HPP_
