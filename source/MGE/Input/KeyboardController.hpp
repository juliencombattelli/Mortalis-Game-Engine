/*
 * KeyboardController.hpp
 *
 *  Created on: 27 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_KEYBOARDCONTROLLER_HPP_
#define MGE_INPUT_KEYBOARDCONTROLLER_HPP_

#include <MGE/Input/Controller.hpp>

namespace mge
{

class KeyboardController : public Controller
{
public:
	KeyboardController();
	virtual ~KeyboardController();
};

} // namespace mge

#endif /* MGE_INPUT_KEYBOARDCONTROLLER_HPP_ */
