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

namespace mge
{

template<class resourceType>
auto ResourceManager::getHolder() const
	-> TemplateResourceHolder<resourceType>*
{
	TemplateResourceHolder<resourceType>* handler = nullptr;

	auto it = m_holders.find(typeid(resourceType).name());

	if(it != m_holders.end())
		handler = static_cast<TemplateResourceHolder<resourceType>*>(it->second.get());

	if(handler == nullptr) // error : handler not find
		std::cout << "handler not find" << std::endl;

	return handler;
}

template<class handlerType>
void ResourceManager::registerHolder()
{
	std::string typeName = typeid(typename handlerType::ResourceType).name();

	if(m_holders.find(typeName) == m_holders.end())
		m_holders.emplace(typeName, std::make_unique<handlerType>());
	else // error : handler already registered
		std::cout << "handler already registered" << std::endl;
}

} // namespace mge

#endif // RESOURCEMANAGER_INL_
