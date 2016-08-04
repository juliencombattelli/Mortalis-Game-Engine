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

