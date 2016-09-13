//============================================================================
// Name        : StdIfstreamAdaptor.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Sep 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef INPUTFILEWRAPPER_HPP_
#define INPUTFILEWRAPPER_HPP_

#include <MGE/Resource/ResourceAdaptor.hpp>

#include <fstream>

namespace mge
{

struct StdIfstreamAdaptor : ResourceAdaptor<std::ifstream>
{
	virtual ~StdIfstreamAdaptor() = default;
	virtual bool load(const std::string& filename) override
	{
		m_resource.open(filename);
		if(not m_resource.is_open())
			std::cout << "Failed to open file \"" + filename + "\"." << std::endl;
		return m_resource.is_open();
	}
};

} // namespace mge

#endif // INPUTFILEWRAPPER_HPP_
