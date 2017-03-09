/*
 * ActionFSM.hpp
 *
 *  Created on: 28 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_ACTIONFSM_HPP_
#define MGE_INPUT_ACTIONFSM_HPP_

#include <SFML/System/Clock.hpp>
#include <cstdint>

namespace mge
{

class ActionFSM
{
	struct ActionState
	{
		bool isActionSelected;
		bool isActionSelectedOnce;
		bool isActionSelectedCont;
	};

	enum FSMState : int8_t
	{
		actionNotSelected,
		actionSelected,
		actionContSelected
	};

public:

	ActionFSM();

	void update(bool isActionSelected);

	bool isSelected() const;
	bool isSelectedOnce() const;
	bool isSelectedCont() const;

private:

	ActionState m_state;
	FSMState m_FSMState;
	sf::Clock m_timer;
};


} // namespace mge


#endif /* MGE_INPUT_ACTIONFSM_HPP_ */
