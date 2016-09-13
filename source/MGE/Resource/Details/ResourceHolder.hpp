//============================================================================
// Name        : ResourceHolder.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 3, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef RESOURCEHOLDER_HPP_
#define RESOURCEHOLDER_HPP_

#include <MGE/Resource/Details/BaseResourceHolder.hpp>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Shader.hpp>
#include <SFML/Audio/SoundBuffer.hpp>

#include <map>
#include <typeinfo>
#include <memory>

namespace mge
{

template<class TResource>
class ResourceHolder : public BaseResourceHolder
{
private:

	struct ResourceData;

	using ResourceMap = std::map<std::string, ResourceData>;
	using Iterator = typename ResourceMap::iterator;

public:

	using ResourceType = TResource;

	ResourceHolder();

	virtual ~ResourceHolder() = default;

	std::shared_ptr<TResource> getReference(const std::string& resourceFilename);

	Iterator createResource(const std::string& resourceFilename);

	virtual bool isLoaded(const std::string& resourceFilename) const final;

	virtual bool loadResource(const std::string& resourceFilename) final;

	virtual bool loadAllResources() final;

protected:

	virtual bool load(const std::string& resourceFilename, TResource& resource);

private:

	std::map<std::string, ResourceData> m_resources;

	TResource m_dummyResource;

	struct ResourceData
	{
		std::shared_ptr<TResource> resource; ///< The resource being shared
		bool loaded; ///< Is the resource currently loaded?
	};
};

} // namespace mge

#include <MGE/Resource/Details/ResourceHolder.inl>

#endif // RESOURCEHOLDER_HPP_
