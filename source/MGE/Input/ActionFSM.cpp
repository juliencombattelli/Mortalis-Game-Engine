/*
 * ActionFSM.cpp
 *
 *  Created on: 28 févr. 2017
 *      Author: JulienCombattelli
 */

#include <MGE/Input/ActionFSM.hpp>

namespace mge
{

ActionFSM::ActionFSM() :
	m_state{false,false,false},
	m_FSMState(FSMState::actionNotSelected) {}

void ActionFSM::update(bool isActionSelected)
{
	m_state.isActionSelected = isActionSelected;
	m_state.isActionSelectedOnce = false;
	m_state.isActionSelectedCont = false;

	switch (m_FSMState)
	{
		case FSMState::actionNotSelected:
		{
			if (isActionSelected)
			{
				m_state.isActionSelectedOnce = true;
				m_state.isActionSelectedCont = true;
				m_timer.restart();

				m_FSMState = FSMState::actionSelected;
			}
		}
		break;

		case FSMState::actionSelected:
		{
			if (isActionSelected and (m_timer.getElapsedTime().asMilliseconds() >= 1000))
			{
				m_state.isActionSelectedCont = true;
				m_state.isActionSelectedOnce = false;

				m_timer.restart();

				m_FSMState = FSMState::actionContSelected;
			}
			else if (not isActionSelected)
			{
				m_state.isActionSelectedOnce = false;
				m_state.isActionSelectedCont = false;

				m_FSMState = FSMState::actionNotSelected;
			}
		}
		break;

		case FSMState::actionContSelected:
		{
			if (not isActionSelected)
			{
				m_state.isActionSelectedOnce = false;
				m_state.isActionSelectedCont = false;

				m_FSMState = FSMState::actionNotSelected;
			}
			else if(isActionSelected and (m_timer.getElapsedTime().asMilliseconds() >= 50))
			{
				m_state.isActionSelectedOnce = false;
				m_state.isActionSelectedCont = true;

				m_timer.restart();

				m_FSMState = FSMState::actionContSelected;
			}
		}
		break;

		default:
		{
			m_state.isActionSelectedOnce = false;
			m_state.isActionSelectedCont = false;
			m_FSMState = FSMState::actionContSelected;
		}
	}
}

bool ActionFSM::isSelected() const
{
	return m_state.isActionSelected;
}

bool ActionFSM::isSelectedOnce() const
{
	return m_state.isActionSelectedOnce;
}

bool ActionFSM::isSelectedCont() const
{
	return m_state.isActionSelectedCont;
}

}

