//============================================================================
// Name        : Factory.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 14 mars 2017
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef MUL_FACTORY_HPP_
#define MUL_FACTORY_HPP_

#include <map>
#include <memory>

namespace mul
{

template<class Base>
struct Instanciator
{
	virtual std::unique_ptr<Base> create() = 0;
	virtual ~Instanciator()
	{
	}
};

template<class Base, class Fille>
struct NewInstanciator : Instanciator<Base>
{
	std::unique_ptr<Base> create()
	{
		return std::make_unique<Fille>();
	}
};

template<class Base, class Key>
class Factory
{
	std::map<Key, std::unique_ptr<Instanciator<Base>>> m_map;

public:

	template<class Fille>
	void registerClass(const Key& id)
	{
		m_map[id] = std::make_unique<NewInstanciator<Base, Fille>>();
	}

	std::unique_ptr<Base> create(const Key& id)
	{
		return m_map.at(id)->create();
	}
};

} // namespace mul

#endif // MUL_FACTORY_HPP_
