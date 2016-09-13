//============================================================================
// Name        : ResourceAdaptor.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 6, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCEADAPTOR_HPP_
#define RESOURCEADAPTOR_HPP_

namespace mge
{

template<typename TResource>
struct ResourceAdaptor
{
	using ResourceType = TResource;

	virtual ~ResourceAdaptor() = default;
	virtual bool load(const std::string& filename) = 0;

	ResourceType m_resource;
};

}  // namespace mge

#endif // RESOURCEADAPTOR_HPP_
