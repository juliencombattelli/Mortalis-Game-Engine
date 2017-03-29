//============================================================================
// Name        : Event.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 19 avr. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provides an observer implementation to handling events
//============================================================================

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <vector>
#include <unordered_map>
#include <typeindex>
#include <functional>

namespace mul
{

class Receiver;

class Event
{
public:
	virtual ~Event() = default;
};

enum class NotifyAction
{
	Done,
	UnRegister
};

class Sender
{
public:
	void addReceiver(Receiver& observer);
	void popReceiver(Receiver& observer);
	void raise(Event const& event);

private:
	std::vector<Receiver*> m_receivers;
};

class Receiver
{
public:
	virtual ~Receiver() {}
	virtual NotifyAction onNotify(Sender& sender, Event const& event);

	template<typename TEvent, typename TMethod, typename TObject>
	void addEventHandler(TMethod&& method, TObject&& obj)
	{
		handlers[typeid(TEvent)] = std::bind(method, obj, std::placeholders::_1, std::placeholders::_2);
	}

private:
	std::unordered_map<std::type_index,std::function<void(Sender&, Event const&)>> handlers;
};

} // namespace mul

#endif // EVENT_HPP_
