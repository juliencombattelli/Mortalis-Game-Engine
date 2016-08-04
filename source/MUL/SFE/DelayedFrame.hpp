//============================================================================
// Name        : DelayedFrame.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provide a temporary frame class as an extension of the
//               SFML library
//============================================================================

#ifndef DELAYEDFRAME_HPP_
#define DELAYEDFRAME_HPP_

#if __cplusplus < 201103L
  #error This library needs at least a C++11 compliant compiler
#endif

#include "Frame.hpp"

namespace mul { namespace sfe
{

class DelayedFrame : public Frame
{
public:
	DelayedFrame(const sf::Sprite& sprite, const sf::Time& duration, bool isValid = true);

	virtual ~DelayedFrame();

	virtual bool update(sf::Time deltaTime) override;

protected:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

} // namespace sfe
} // namespace mul

#endif /* DELAYEDFRAME_HPP_ */
