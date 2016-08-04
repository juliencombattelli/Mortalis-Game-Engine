//============================================================================
// Name        : Event.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 23 mai 2016
// Version     :
// Description : 
//============================================================================

#ifndef MGE_CORE_EVENT_EVENT_HPP_
#define MGE_CORE_EVENT_EVENT_HPP_

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


#endif /* MGE_CORE_EVENT_EVENT_HPP_ */

//============================================================================
// Copyright (c) 2013-2016 Julien Combattelli
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//============================================================================
