//============================================================================
// Name        : ResourceManager.inl
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCEMANAGER_INL_
#define RESOURCEMANAGER_INL_

#include <string>

namespace mge
{

template<class resourceType>
auto ResourceManager::getHolder() const
	-> ResourceHolder<resourceType>*
{
	ResourceHolder<resourceType>* holder = nullptr;

	std::string typeName(typeid(resourceType).name());

	auto it = m_holders.find(typeName);

	if(it != m_holders.end())
		holder = static_cast<ResourceHolder<resourceType>*>(it->second.get());

	if(holder == nullptr) // error : handler not find
		throw std::runtime_error(
			"Holder \"" + typeName + "\" not find.\n\n"+
			"Don't you forget to register the holder in mge::Engine::init() ?\n\n"+
			"You also can use getHolderOrCreate() instead of getHolder().");

	return holder;
}

template<class resourceType>
auto ResourceManager::getHolderOrCreate()
	-> ResourceHolder<resourceType>*
{
	ResourceHolder<resourceType>* holder = nullptr;

	std::string typeName(typeid(resourceType).name());

	auto it = m_holders.find(typeName);

	if(it != m_holders.end())
		holder = static_cast<ResourceHolder<resourceType>*>(it->second.get());
	else
	{
		RegistationResult registation = registerHolder<ResourceHolder<resourceType>>();
		holder = static_cast<ResourceHolder<resourceType>*>(registation.first->second.get());
	}

	if(holder == nullptr) // error : handler not find
		throw std::runtime_error(
			"Holder \"" + typeName + "\" not find.\n\n"+
			"Don't you forget to register the holder in mge::Engine::init() ?\n\n"+
			"You also can use getHolderOrCreate() instead of getHolder().");

	return holder;
}


template<class holderType>
ResourceManager::RegistationResult ResourceManager::registerHolder()
{
	std::string typeName(typeid(typename holderType::ResourceType).name());

	if(m_holders.find(typeName) == m_holders.end())
		return m_holders.emplace(typeName, std::make_unique<holderType>());
	else // error : handler already registered
	{
		std::cout << "handler already registered" << std::endl;
		return {m_holders.end(),false};
	}
}

} // namespace mge

#endif // RESOURCEMANAGER_INL_
