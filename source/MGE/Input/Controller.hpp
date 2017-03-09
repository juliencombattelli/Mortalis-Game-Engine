/*
 * Controller.hpp
 *
 *  Created on: 27 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_CONTROLLER_HPP_
#define MGE_INPUT_CONTROLLER_HPP_

#include <MGE/Config/ActionConfig.hpp>
#include <MGE/Input/Control.hpp>
#include <map>

namespace mge
{

class Controller
{
public:

	virtual ~Controller() {}

	void rebindAction(Action action, int key)
	{
		m_actionMap[action] = key;
	}

	virtual void update()
	{
		// Nothing to do
	}

	virtual bool isSelected(Action action) const
	{
		try
		{
			return m_actionMap.at(action)();
		}
		catch(...)
		{
			return false;
		}
	}

protected:

	std::map<Action,Control> m_actionMap;
};

} // namespace mge

#endif /* MGE_INPUT_CONTROLLER_HPP_ */
