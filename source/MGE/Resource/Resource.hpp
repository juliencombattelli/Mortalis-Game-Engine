//============================================================================
// Name        : Resource.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 4, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCE_HPP_
#define RESOURCE_HPP_

#include <MGE/Resource/ResourceManager.hpp>

#include <MGE/Resource/Details/StdIfstreamAdaptor.hpp>
#include <MGE/Resource/Details/SFMLResourceAdaptor.hpp>
#include <MGE/Resource/Details/ResourceTraits.hpp>
#include <MGE/Resource/Details/ResourceHolder.hpp>

#include <string>

namespace sf
{

class Font;
class Texture;

}

namespace mge
{

template<class TResource, typename Enable = void>
class Resource
{
	static_assert(mge::traits::hasLoadMethod<TResource>::value,
		"TResource must have a 'bool load(const std::string&)' method. Use mge::ResourceAdaptor class.");

public:

	Resource(const std::string& resourceFilename, ResourceManager& resourceManager);

	virtual ~Resource() = default;

	bool isLoaded() const;

	std::string getFilename() const;

	const TResource& get() const;

	TResource* operator->();

	template<class R>
	friend void swap(Resource<R>& first, Resource<R>& second);

protected:

	ResourceHolder<TResource>* m_resourceHolder;
	std::string m_resourceFilename;
	std::shared_ptr<TResource> m_resource;

	Resource(const Resource<TResource>& copy) = delete; // TODO : define
	Resource<TResource>& operator=(Resource<TResource> rhs) = delete; // TODO : define
};

///////////////////////////////////////////////////////////////////////////////
/// Template specialization which allow using mge::ResourceAdaptor
///////////////////////////////////////////////////////////////////////////////

template<class TResource>
class Resource<TResource, typename std::enable_if<mge::traits::hasResourceType<TResource>::value>::type>
{
public:

	Resource(const std::string& resourceFilename, ResourceManager& resourceManager);

	virtual ~Resource() = default;

	bool isLoaded() const;

	std::string getFilename() const;

	typename TResource::ResourceType& get();

	typename TResource::ResourceType* operator->();

	template<class R>
	friend void swap(Resource<R>& first, Resource<R>& second);

protected:

	ResourceHolder<TResource>* m_resourceHolder;
	std::string m_resourceFilename;
	std::shared_ptr<TResource> m_resource;

	Resource(const Resource<TResource>& copy) = delete; // TODO : define
	Resource<TResource>& operator=(Resource<TResource> rhs) = delete; // TODO : define
};

using TextureResource = Resource<SFMLResourceAdaptor<sf::Texture>>;
using FontResource = Resource<SFMLResourceAdaptor<sf::Font>>;
using InputFileResource = Resource<StdIfstreamAdaptor>;

} // namespace mge

#include "Details/Resource.inl"

#endif // RESOURCE_HPP_
