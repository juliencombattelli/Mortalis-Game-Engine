//============================================================================
// Name        : Event.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 19 avr. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provides an observer implementation to handling events
//============================================================================

#include "Event.hpp"

#include <algorithm>
#include <stdexcept>

namespace mul
{

void Sender::addReceiver(Receiver& observer)
{
	if(std::find(std::begin(m_receivers), std::end(m_receivers), &observer) != std::end(m_receivers))
	{
		throw std::runtime_error("addReceiver(): receiver already registered");
	}
	m_receivers.push_back(&observer);
}

void Sender::popReceiver(Receiver& observer)
{
	m_receivers.erase(std::remove(std::begin(m_receivers), std::end(m_receivers),&observer), std::end(m_receivers));
}

void Sender::raise(Event const& event)
{
	std::vector<Receiver*> deadReceivers;
	for(Receiver* receiver : m_receivers)
	{
		if(receiver->onNotify(*this, event) == NotifyAction::UnRegister)
		{
			deadReceivers.push_back(receiver);
		}
	}

	auto newEnd = std::end(m_receivers);
	for (Receiver* dead : deadReceivers)
	{
		newEnd = std::remove(std::begin(m_receivers), newEnd, dead);
	}
	m_receivers.erase(newEnd, std::end(m_receivers));
}

NotifyAction Receiver::onNotify(Sender& sender, Event const& event)
{
	auto find = handlers.find(typeid(event));

	if(find != handlers.end())
	{
		find->second(sender, event);
		return NotifyAction::Done;
	}
	else
	{
		return NotifyAction::UnRegister;
	}

}

} // namespace mul
