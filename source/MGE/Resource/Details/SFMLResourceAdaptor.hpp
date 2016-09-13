//============================================================================
// Name        : SFMLResourceAdaptor.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 6, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef SFMLLOADFROMFILEADAPTOR_HPP_
#define SFMLLOADFROMFILEADAPTOR_HPP_

#include <MGE/Resource/ResourceAdaptor.hpp>

#include <MGE/Resource/Details/ResourceTraits.hpp>

#include <SFML/Graphics.hpp>

namespace mge
{

template<typename TSFMLResource>
struct SFMLResourceAdaptor : ResourceAdaptor<TSFMLResource>
{
	virtual ~SFMLResourceAdaptor() = default;
	virtual bool load(const std::string& filename) override
	{
		return this->m_resource.loadFromFile(filename); // this is necessary with gcc6.1
	}
};

}  // namespace mge

#endif // SFMLLOADFROMFILEADAPTOR_HPP_
