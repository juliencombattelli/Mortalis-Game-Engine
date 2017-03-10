/*
 * InputManager.cpp
 *
 *  Created on: 28 févr. 2017
 *      Author: JulienCombattelli
 */

#include <MGE/Input/InputManager.hpp>
#include <MGE/Input/KeyboardController.hpp>
#include <MGE/Input/Dualshock4Controller.hpp>

namespace mge
{

InputManager::InputManager() :
	m_dpad({Action::moveUp, Action::moveDown, Action::moveRight, Action::moveLeft})
{

}

void InputManager::init()
{
	m_controllers.emplace_back(std::make_unique<KeyboardController>());
	m_controllers.emplace_back(std::make_unique<Dualshock4Controller>());
	m_fsmMap[Action::pause] = ActionFSM();
	m_fsmMap[Action::accept] = ActionFSM();
	m_fsmMap[Action::moveUp] = ActionFSM();
	m_fsmMap[Action::moveDown] = ActionFSM();
	m_fsmMap[Action::moveLeft] = ActionFSM();
	m_fsmMap[Action::moveRight] = ActionFSM();
}

void InputManager::update()
{
	for(auto& actionFsmPair : m_fsmMap)
	{
		bool isActionSelected = false;
		for(auto& ctrl : m_controllers)
		{
			isActionSelected = isActionSelected || ctrl->isSelected(actionFsmPair.first);
		}
		actionFsmPair.second.update(isActionSelected);
	}

	std::map<Action,bool> mapForUpdate;

	for(auto& action : directionalActions)
		mapForUpdate[action] = isSelected(action);

	m_dpad.update(mapForUpdate);
}

bool InputManager::isSelected(Action action) const
{
	return m_fsmMap.at(action).isSelected();
}

bool InputManager::isSelectedOnce(Action action) const
{
	return m_fsmMap.at(action).isSelectedOnce();
}

bool InputManager::isSelectedCont(Action action) const
{
	return m_fsmMap.at(action).isSelectedCont();
}

bool InputManager::isDPadSelected(Action action) const
{
	return m_dpad.isSelected(action);
}

} // namespace mge

