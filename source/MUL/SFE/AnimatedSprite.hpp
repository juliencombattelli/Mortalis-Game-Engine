//============================================================================
// Name        : AnimatedSprite.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 27 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provides a template animated sprite class based on
//               sf::Sprite. The template parameter is using to index
//               animation
//============================================================================

#ifndef ANIMATEDSPRITE_INCLUDE
#define ANIMATEDSPRITE_INCLUDE

#include <memory>
#include <map>
#include <vector>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include <MUL/SFE/Frame.hpp>
#include <MUL/SFE/DelayedFrame.hpp>
#include <MUL/Memory.hpp>

namespace mul { namespace sfe
{

template<class T>
class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
	using AnimationIDType = T;

	AnimatedSprite(bool paused = true, bool looped = false);

	void addFrame(const AnimationIDType& animation, const sf::Sprite& sprite, sf::Time duration);

	void addFrame(const AnimationIDType& animation, const sf::Texture& texture, const sf::IntRect& rect, sf::Time duration);

	void addDelayedFrame(const AnimationIDType& animation, const sf::Sprite& sprite, sf::Time duration, bool isActive = true);

	void addDelayedFrame(const AnimationIDType& animation, const sf::Texture& texture, const sf::IntRect& rect, sf::Time duration, bool isActive = true);

	void update(sf::Time deltaTime);

	bool isValid() const;

	void play();

	void play(const AnimationIDType& animation);

	void pause();

	void stop();

	void setLooped(bool looped);

	sf::FloatRect getLocalBounds() const;

	sf::FloatRect getGlobalBounds() const;

	bool isLooped() const;

	bool isPlaying() const;

protected:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    using Animation = std::vector<std::unique_ptr<Frame>>;

	std::map<AnimationIDType, Animation> m_animations;
	AnimationIDType m_currentAnimation;
	std::size_t m_currentFrame;
	bool m_isPaused;
	bool m_isLooped;
};

template<class AnimationIDType>
AnimatedSprite<AnimationIDType>::AnimatedSprite(bool paused, bool looped) :
	    m_currentFrame(0), m_isPaused(paused), m_isLooped(looped)
{

}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::addFrame(const AnimationIDType& animation, const sf::Sprite& sprite, sf::Time duration)
{
	m_animations[animation].push_back(mul::make_unique<Frame>(sprite, duration));
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::addFrame(const AnimationIDType& animation, const sf::Texture& texture, const sf::IntRect& rect, sf::Time duration)
{
	m_animations[animation].push_back(mul::make_unique<Frame>(sf::Sprite(texture, rect), duration));
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::addDelayedFrame(const AnimationIDType& animation, const sf::Sprite& sprite, sf::Time duration, bool isActive)
{
	m_animations[animation].push_back(mul::make_unique<DelayedFrame>(sprite, duration));
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::addDelayedFrame(const AnimationIDType& animation, const sf::Texture& texture, const sf::IntRect& rect, sf::Time duration, bool isActive)
{
	m_animations[animation].push_back(mul::make_unique<DelayedFrame>(sf::Sprite(texture, rect), duration));
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::update(sf::Time deltaTime)
{
	if(isValid() and not m_isPaused and m_animations[m_currentAnimation][m_currentFrame]->update(deltaTime))
	{
		if (m_currentFrame + 1 < m_animations[m_currentAnimation].size())
		{
			m_animations[m_currentAnimation][m_currentFrame]->validate();
			m_currentFrame++;
		}
		else
		{
			m_currentFrame = 0;
			m_isPaused = m_isLooped ? false : true;
		}
	}
}

template<class AnimationIDType>
bool AnimatedSprite<AnimationIDType>::isValid() const
{
	bool isAnimationValid = true;
	if (m_animations.empty())
		isAnimationValid = false;
	if (m_animations.find(m_currentAnimation) == m_animations.end())
		isAnimationValid = false;
	return isAnimationValid;
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::play()
{
	m_isPaused = false;
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::play(const AnimationIDType& animation)
{
	m_isPaused = false;
	m_currentAnimation = animation;
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::pause()
{
	m_isPaused = true;
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::stop()
{
	m_isPaused = true;
	m_currentFrame = 0;
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::setLooped(bool looped)
{
	m_isLooped = looped;
}

template<class AnimationIDType>
sf::FloatRect AnimatedSprite<AnimationIDType>::getLocalBounds() const
{
	auto it = m_animations.find(m_currentAnimation);
	if(it != m_animations.end())
		return it->second[m_currentFrame]->sprite().getLocalBounds();
	else
		return sf::FloatRect(0.f,0.f,0.f,0.f);
}

template<class AnimationIDType>
sf::FloatRect AnimatedSprite<AnimationIDType>::getGlobalBounds() const
{
	return getTransform().transformRect(getLocalBounds());
}

template<class AnimationIDType>
bool AnimatedSprite<AnimationIDType>::isLooped() const
{
	return m_isLooped;
}

template<class AnimationIDType>
bool AnimatedSprite<AnimationIDType>::isPlaying() const
{
	return not m_isPaused;
}

template<class AnimationIDType>
void AnimatedSprite<AnimationIDType>::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(isValid())
	{
		states.transform *= getTransform();
		auto it = m_animations.find(m_currentAnimation);
		target.draw(*it->second[m_currentFrame], states);
	}
}

} // namespace sfe
} // namespace mul

#endif // ANIMATEDSPRITE_INCLUDE
