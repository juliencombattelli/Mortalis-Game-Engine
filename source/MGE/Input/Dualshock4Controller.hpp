/*
 * Dualshock4Controller.hpp
 *
 *  Created on: 28 févr. 2017
 *      Author: JulienCombattelli
 */

#ifndef MGE_INPUT_DUALSHOCK4CONTROLLER_HPP_
#define MGE_INPUT_DUALSHOCK4CONTROLLER_HPP_

#include <MGE/Input/Controller.hpp>
#include <MGE/Config/ActionConfig.hpp>
#include <MUL/SFE/Joystick.hpp>
#include <SFML/Window/Joystick.hpp>

namespace mge
{
/*
 * Axis		DS4 Joystick
 * X		Joystick Lx
 * Y		Joystick Ly
 * Z		Joystick Rx
 * R		Joystick Ry
 * U		Joystick R2
 * V		Joystick L2
 * PovX		Left/Right
 * PovY		Up/Down
 */
class Dualshock4Controller : public Controller
{
public:

	enum Buttons
	{
		ButtonSquare = 0,
		ButtonCross,
		ButtonCircle,
		ButtonTriangle,
		ButtonL1,
		ButtonR1,
		ButtonL2,
		ButtonR2,
		ButtonShare,
		ButtonOptions,
		ButtonL3,
		ButtonR3,
		ButtonPS,
		ButtonTouchPad,
	};

	enum Axes
	{
		AxeLeftX 	= sf::Joystick::X,
		AxeLeftY 	= sf::Joystick::Y,
		AxeRightX 	= sf::Joystick::Z,
		AxeRightY 	= sf::Joystick::R,
		AxeR2 		= sf::Joystick::U,
		AxeL2 		= sf::Joystick::V,
		AxePadX 	= sf::Joystick::PovX,
		AxePadY 	= sf::Joystick::PovY,
	};

	static const unsigned int VendorID = 0x054C;
	static const unsigned int ProductID = 0x05C4;

	Dualshock4Controller();

	virtual ~Dualshock4Controller();

private:

	unsigned int m_controllerID;
};

} // namespace mge

#endif /* MGE_INPUT_DUALSHOCK4CONTROLLER_HPP_ */
