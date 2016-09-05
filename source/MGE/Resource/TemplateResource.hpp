//============================================================================
// Name        : TemplateResource.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef TEMPLATERESOURCE_HPP_
#define TEMPLATERESOURCE_HPP_

#include <MGE/Resource/ResourceManager.hpp>
#include <MGE/Resource/TemplateResourceHolder.hpp>

#include <string>

namespace sf
{

class Font;
class Texture;

}

namespace mge
{

template<class TResource>
class TemplateResource
{
public:

	TemplateResource(const std::string resourceFilename, const ResourceManager& resourceManager);

	virtual ~TemplateResource() = default;

	bool isLoaded() const;

	std::string getFilename() const;

	TResource& getResource();

	const std::string getFilename();

	template<class R>
	friend void swap(TemplateResource<R>& first, TemplateResource<R>& second);

protected:

	TemplateResourceHolder<TResource>* m_resourceHolder;
	std::string m_resourceFilename;
	std::shared_ptr<TResource> m_resource;

	TemplateResource(const TemplateResource<TResource>& tresource) = delete; // TODO : define
	TemplateResource<TResource>& operator=(TemplateResource<TResource> rhs) = delete; // TODO : define
};

using FontResource = TemplateResource<sf::Font>;
using TextureResource = TemplateResource<sf::Texture>;
using InputFileResource = TemplateResource<InputFileWrapper>;

} // namespace mge

#include <MGE/Resource/Details/TemplateResource.inl>

#endif // TEMPLATERESOURCE_HPP_
