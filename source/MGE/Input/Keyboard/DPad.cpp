//============================================================================
// Name        : DPad.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 29 juin 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description :
//============================================================================

#include <MGE/Input/Keyboard/DPad.hpp>

namespace mge
{

DPad::DPad(const std::vector<Action>& directionnalActions)
{
	for(auto dAction : directionnalActions)
		m_DKeys[dAction] = {false, false, 0};
}

DPad::~DPad()
{

}

void DPad::update(const std::map<Action, bool>& dKeysState)
{
	for(auto& dKey : dKeysState)
		m_DKeys[dKey.first].isPressed = dKey.second;

    for(auto& dKey : m_DKeys)
	{
		if(not dKey.second.wasPressed)
		{
			if(dKey.second.isPressed)
			{
				dKey.second.wasPressed = true;

				DKeyState* highestPriorityKey = findHighestPriority();

				if(highestPriorityKey != nullptr)
					dKey.second.priority = highestPriorityKey->priority + 1 ;
				else
					dKey.second.priority = 1;
			}
		}
		else
		{
			if(not dKey.second.isPressed)
			{
				dKey.second.wasPressed = false;
				dKey.second.priority = 0;
			}
		}
	}

    adjustPriority();

    enableHighestPriorityKey();
}

bool DPad::isPressed(Action action) const
{
	auto it = m_DKeys.find(action);
	if(it != m_DKeys.end())
		return it->second.isPressed;
	else
		return false;
}

DPad::DKeyState* DPad::findHighestPriority()
{
    int highestPriority = 0;
    DKeyState* highestPriorityKey = nullptr;

    for(auto& dKey : m_DKeys)
    {
    	if(dKey.second.priority > highestPriority)
    	{
    		highestPriority = dKey.second.priority;
    		highestPriorityKey = &dKey.second;
    	}
    }

    return highestPriorityKey;
}

void DPad::enableHighestPriorityKey()
{
    for(auto& dKey : m_DKeys)
        dKey.second.isPressed = false;

    DKeyState* highestPriorityKey = findHighestPriority();

    if(highestPriorityKey != nullptr)
    	highestPriorityKey->isPressed = true;
}

void DPad::adjustPriority()
{
	// set periodically all priorities to the range [0, Directional key number]
	// useless for now
}

} // namespace mge
