/*
 * InputManager.hpp
 *
 *  Created on: 28 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_INPUTMANAGER_HPP_
#define MGE_INPUT_INPUTMANAGER_HPP_

#include <MGE/Input/ActionFSM.hpp>
#include <MGE/Input/Controller.hpp>
#include <memory>
#include <map>
#include <vector>

namespace mge
{

enum class Action : std::int8_t;

class InputManager
{
public:

	InputManager();

	void update();

	bool isSelected(Action action) const;
	bool isSelectedOnce(Action action) const;
	bool isSelectedCont(Action action) const;

private:

	std::map<Action, ActionFSM> m_fsmMap;
	std::vector<std::unique_ptr<Controller>> m_controllers;
};

} // namespace mge

#endif /* MGE_INPUT_INPUTMANAGER_HPP_ */
