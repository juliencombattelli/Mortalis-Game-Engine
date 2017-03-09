/*
 * Control.hpp
 *
 *  Created on: 9 mars 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_CONTROL_HPP_
#define MGE_INPUT_CONTROL_HPP_

#include <functional>

namespace mge
{

class Control
{
public:

	// Default ctor
	Control();

	// Button-type control ctor
	Control(int buttonId);

	// Axe-type control ctor
	Control(int axeId, int controllerId, std::function<bool(const Control&)> pred);

	bool operator()() const;

	static bool Button(const Control& ctrl);

	static bool NegativAxe(const Control& ctrl);

	static bool PositivAxe(const Control& ctrl);

private:

	int m_id;
	int m_controllerId;
	std::function<bool(const Control&)> m_predicate;
};

} // namespace mge

#endif /* MGE_INPUT_CONTROL_HPP_ */
