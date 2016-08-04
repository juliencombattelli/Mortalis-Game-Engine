//============================================================================
// Name        : ResourceManager.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 3, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#ifndef RESOURCEMANAGER_HPP_
#define RESOURCEMANAGER_HPP_

#include <MGE/Resource/TemplateResourceHolder.hpp>
#include <map>
#include <typeinfo>
#include <memory>
#include <iostream>

namespace mge
{

class ResourceManager
{
public:

	ResourceManager() = default;
	virtual ~ResourceManager() = default;

	template<class resourceType>
	TemplateResourceHolder<resourceType>* getHolder() const;

	template<class handlerType>
	void registerHolder();

	bool loadAllResources();

private:

	std::map<std::string, std::unique_ptr<AbstractResourceHolder>> m_holders;

	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;
};

} // namespace mge

#include <MGE/Resource/Details/ResourceManager.inl>

#endif // RESOURCEMANAGER_HPP_
