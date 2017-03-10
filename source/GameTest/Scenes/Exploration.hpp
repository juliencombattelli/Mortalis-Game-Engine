#ifndef EXPLORATION_HPP_INCLUDED
#define EXPLORATION_HPP_INCLUDED

#include <MGE/Core/Scene/Scene.hpp>
#include <MGE/Resource/Resource.hpp>
#include <MUL/SFE/AnimatedSprite.hpp>

namespace rpg
{

class Exploration : public mge::Scene
{
public:
    Exploration(mge::ResourceManager& resourceManager);
    virtual ~Exploration();

    virtual void handleEvent(sf::Event& event, const mge::InputManager& input) final;
    virtual void update(float elapsedTime) final;
    virtual void draw(sf::RenderTarget& window) final;

    virtual void pause() final;
    virtual void resume() final;

private:

    void updateView();

    sf::Texture         mTexture;
    sf::View            mView;
    //rpg::TileMapDrawer  mTileMap;
    //rpg::HerosSprite    mHeros;
    mge::TextureResource m_Actor1Texture;
    mul::sfe::AnimatedSprite<std::string> mHeros;

};

}


#endif // EXPLORATION_HPP_INCLUDED
