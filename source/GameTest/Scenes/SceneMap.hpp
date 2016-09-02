//============================================================================
// Name        : SceneMap.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 21, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef SCENEMAP_HPP_
#define SCENEMAP_HPP_


#include <MGE/Core/Scene/Scene.hpp>
#include <MGE/Resource/TemplateResource.hpp>
#include <MGE/Config/MapConfig.hpp>

#include <MUL/SFE/AnimatedSprite.hpp>

namespace game
{

class SceneMap : public mge::Scene
{
public:
	SceneMap(mge::ResourceManager& resourceManager);
    virtual ~SceneMap() = default;

    virtual void handleEvent(sf::Event& event, const mge::Keyboard& keyboard) final;
    virtual void update(float elapsedTime) final;
    virtual void draw(sf::RenderTarget& window) final;

    virtual void pause() final;
    virtual void resume() final;

private:

    void updateView();

    sf::View m_view;
    mge::Map m_map;
    mge::TextureResource m_actor1Texture;
    mge::TextureResource m_worldA2Texture;
    mul::sfe::AnimatedSprite<std::string> m_heros;
};

} // namespace game

#endif // SCENEMAP_HPP_
