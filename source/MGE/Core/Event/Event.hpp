//============================================================================
// Name        : Event.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 23 May 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : 
//============================================================================

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <MGE/Core/Status/Status.hpp>
#include <MUL/Event/Event.hpp>

namespace mge
{

struct QuitEvent : public mul::Event
{
	QuitEvent(Status exitCode) : exitStatus(exitCode) {}
	virtual ~QuitEvent() {}
	Status exitStatus;
};

// TODO : make it template
struct ResourceHandlerRequestEvent : public mul::Event
{
	ResourceHandlerRequestEvent(std::string id) : handlerID(id) {}
	virtual ~ResourceHandlerRequestEvent() {}
	std::string handlerID;
};

}

#endif // EVENT_HPP_
