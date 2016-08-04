//============================================================================
// Name        : TemplateResourceHolder.inl
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef TEMPLATERESOURCEHOLDER_INL_
#define TEMPLATERESOURCEHOLDER_INL_

namespace mge
{

template<class R>
TemplateResourceHolder<R>::TemplateResourceHolder() :
	AbstractResourceHolder(typeid(R).name())
{

}

template<class R>
auto TemplateResourceHolder<R>::getReference(const std::string& resourceFilename)
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
		loadResource(resourceFilename);
	}

	if(resource == nullptr)
		resource = std::make_shared<R>(m_dummyResource);

	return resource;
}

template<class R>
auto TemplateResourceHolder<R>::isLoaded(const std::string& resourceFilename) const
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
auto TemplateResourceHolder<R>::createResource(const std::string& resourceFilename)
	-> typename TemplateResourceHolder<R>::Iterator
{
	ResourceData resourceData;
	resourceData.resource = std::make_shared<R>();
	resourceData.loaded = false;

	return m_resources.insert({resourceFilename, resourceData}).first;
}

template<class R>
auto TemplateResourceHolder<R>::loadResource(const std::string& resourceFilename)
	-> bool
{
	bool loaded = false;

	auto it = m_resources.find(resourceFilename);

	if(it == m_resources.end())
		it = createResource(resourceFilename);

	if(it->second.loaded == false)
		it->second.loaded = loadFromFile(resourceFilename, *(it->second.resource));

	loaded = it->second.loaded;

	return loaded;
}

template<class R>
auto TemplateResourceHolder<R>::loadAllResources()
	-> bool
{
	bool succeed = true;

	for(auto& resource : m_resources)
	{
		if(resource.second.loaded == false)
			resource.second.loaded = loadFromFile(resource.first, *(resource.second.resource));

		succeed &= resource.second.loaded;
	}

	return succeed;
}

template<class R>
auto TemplateResourceHolder<R>::loadFromFile(const std::string& resourceFilename, R& resource)
	-> bool
{
	return resource.loadFromFile(resourceFilename);
}

} // namespace mge

#endif // TEMPLATERESOURCEHOLDER_INL_
