//============================================================================
// Name        : ResourceManager.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Jul 5, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#include <MGE/Resource/ResourceManager.hpp>

namespace mge
{

bool ResourceManager::loadAllResources()
{
	bool succeed = true;

	for(auto& it : m_holders)
		succeed &= it.second->loadAllResources();
		
	return succeed;
}

} // namespace mge

