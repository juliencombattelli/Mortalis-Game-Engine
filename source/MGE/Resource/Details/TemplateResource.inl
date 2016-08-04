//============================================================================
// Name        : TemplateResource.inl
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef TEMPLATERESOURCE_INL_
#define TEMPLATERESOURCE_INL_

#include <utility>

namespace mge
{

template<class R>
TemplateResource<R>::TemplateResource(const std::string resourceFilename, const ResourceManager& resourceManager) :
	m_resourceHolder(resourceManager.getHolder<R>()),
	m_resourceFilename(resourceFilename),
	m_resource(m_resourceHolder->getReference(resourceFilename))
{

}

template<class R>
bool TemplateResource<R>::isLoaded() const
{
	return m_resourceHolder->isLoaded(m_resourceFilename);
}

template<class R>
std::string TemplateResource<R>::getFilename() const
{
	return m_resourceFilename;
}

template<class R>
R& TemplateResource<R>::getResource()
{
	if(m_resourceHolder->isLoaded(m_resourceFilename) == false)
		if(m_resourceHolder->loadResource(m_resourceFilename))
			m_resource = m_resourceHolder->getReference(m_resourceFilename);

	return *m_resource;
}

template<class R>
const std::string TemplateResource<R>::getFilename()
{
	return m_resourceHolder->getFilename(m_resourceFilename);
}

template<class R>
void swap(TemplateResource<R>& first, TemplateResource<R>& second)
{
	std::swap(first.m_resource, second.m_resource);
	std::swap(first.m_resourceFilename, second.m_resourceFilename);
}

} // namespace mge

#endif // TEMPLATERESOURCE_INL_
