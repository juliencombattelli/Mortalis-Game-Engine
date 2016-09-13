//============================================================================
// Name        : ResourceHolder.inl
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCEHOLDER_INL_
#define RESOURCEHOLDER_INL_

#include <MGE/Resource/Details/ResourceExceptions.hpp>

namespace mge
{

template<class R>
ResourceHolder<R>::ResourceHolder() :
	BaseResourceHolder(typeid(R).name())
{

}

template<class R>
auto ResourceHolder<R>::getReference(const std::string& resourceFilename)
	-> std::shared_ptr<R>
{
	std::shared_ptr<R> resource;

	auto it = m_resources.find(resourceFilename);

	if(it != m_resources.end())
	{
		resource = it->second.resource;
	}
	else
	{
		auto it = createResource(resourceFilename);
		resource = it->second.resource;
		if(not loadResource(resourceFilename))
			throw LoadResourceException(resourceFilename);
	}

	if(resource == nullptr)
		resource = std::make_shared<R>();

	return resource;
}

template<class R>
auto ResourceHolder<R>::isLoaded(const std::string& resourceFilename) const
	-> bool
{
	bool loaded = false;

	auto it = m_resources.find(resourceFilename);

	if(it != m_resources.end())
		loaded = it->second.loaded;
	else
		throw std::out_of_range("TemplateResourceHandler::isLoaded() : \
			passing resource filename corresponding to a not created resource");

	return loaded;
}

template<class R>
auto ResourceHolder<R>::createResource(const std::string& resourceFilename)
	-> typename ResourceHolder<R>::Iterator
{
	ResourceData resourceData;
	resourceData.resource = std::make_shared<R>();
	resourceData.loaded = false;

	return m_resources.emplace(resourceFilename, resourceData).first;
}

template<class R>
auto ResourceHolder<R>::loadResource(const std::string& resourceFilename)
	-> bool
{
	bool loaded = false;

	auto it = m_resources.find(resourceFilename);

	if(it == m_resources.end())
		it = createResource(resourceFilename);

	if(it->second.loaded == false)
		it->second.loaded = load(resourceFilename, *(it->second.resource));

	loaded = it->second.loaded;

	return loaded;
}

template<class R>
auto ResourceHolder<R>::loadAllResources()
	-> bool
{
	bool succeed = true;

	for(auto& resource : m_resources)
	{
		if(resource.second.loaded == false)
			resource.second.loaded = load(resource.first, *(resource.second.resource));

		succeed &= resource.second.loaded;
	}

	return succeed;
}

template<class R>
auto ResourceHolder<R>::load(const std::string& resourceFilename, R& resource)
	-> bool
{
	return resource.load(resourceFilename);
}

} // namespace mge

#endif // RESOURCEHOLDER_INL_
