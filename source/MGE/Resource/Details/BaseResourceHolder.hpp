//============================================================================
// Name        : BaseResourceHolder.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 3, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef BASERESOURCEHOLDER_HPP_
#define BASERESOURCEHOLDER_HPP_

#include <string>

namespace mge
{

class BaseResourceHolder
{
public:
	BaseResourceHolder(const std::string& id) : m_id(id) {}
	BaseResourceHolder(const BaseResourceHolder&) = delete;
	BaseResourceHolder& operator=(const BaseResourceHolder&) = delete;
	virtual ~BaseResourceHolder() = default;

	std::string getId() const { return m_id; }

	virtual bool isLoaded(const std::string& resourceID) const = 0;

	virtual bool loadResource(const std::string& resourceID) = 0;

	virtual bool loadAllResources() = 0;

private:

	const std::string m_id;
};

} // namespace mge

#endif // BASERESOURCEHOLDER_HPP_
