//============================================================================
// Name        : Resource.inl
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCE_INL_
#define RESOURCE_INL_

#include <utility>

namespace mge
{

template<class R, typename E>
Resource<R,E>::Resource(const std::string& resourceFilename, ResourceManager& resourceManager) :
	m_resourceHolder(resourceManager.getHolderOrCreate<R>()),
	m_resourceFilename(resourceFilename),
	m_resource(m_resourceHolder->getReference(resourceFilename))
{

}

template<class R, typename E>
auto Resource<R,E>::isLoaded() const
	-> bool
{
	return m_resourceHolder->isLoaded(m_resourceFilename);
}

template<class R, typename E>
auto Resource<R,E>::getFilename() const
	-> std::string
{
	return m_resourceFilename;
}

template<class R, typename E>
auto Resource<R,E>::get() const
	-> const R&
{
	if(m_resourceHolder->isLoaded(m_resourceFilename) == false)
		if(m_resourceHolder->loadResource(m_resourceFilename))
			m_resource = m_resourceHolder->getReference(m_resourceFilename);

	return *m_resource;
}

template<class R, typename E>
auto Resource<R,E>::operator->()
	-> R*
{
	return &get();
}

template<class R, typename E>
void swap(Resource<R,E>& first, Resource<R,E>& second)
{
	std::swap(first.m_resource, second.m_resource);
	std::swap(first.m_resourceFilename, second.m_resourceFilename);
}

///////////////////////////////////////////////////////////////////////////////

template<class R>
Resource<R,typename std::enable_if<mge::traits::hasResourceType<R>::value>::type>::
Resource(const std::string& resourceFilename, ResourceManager& resourceManager) :
	m_resourceHolder(resourceManager.getHolderOrCreate<R>()),
	m_resourceFilename(resourceFilename),
	m_resource(m_resourceHolder->getReference(resourceFilename))
{

}

template<class R>
auto Resource<R,typename std::enable_if<mge::traits::hasResourceType<R>::value>::type>::
isLoaded() const
	-> bool
{
	return m_resourceHolder->isLoaded(m_resourceFilename);
}

template<class R>
auto Resource<R,typename std::enable_if<mge::traits::hasResourceType<R>::value>::type>::
getFilename() const
	-> std::string
{
	return m_resourceFilename;
}

template<class R>
auto Resource<R,typename std::enable_if<mge::traits::hasResourceType<R>::value>::type>::
get()
	-> typename R::ResourceType&
{
	if(m_resourceHolder->isLoaded(m_resourceFilename) == false)
		if(m_resourceHolder->loadResource(m_resourceFilename))
			m_resource = m_resourceHolder->getReference(m_resourceFilename);

	return m_resource.get()->m_resource;
}

template<class R>
auto Resource<R,typename std::enable_if<mge::traits::hasResourceType<R>::value>::type>::
operator->()
	-> typename R::ResourceType*
{
	return &get();
}

} // namespace mge

#endif // RESOURCE_INL_
