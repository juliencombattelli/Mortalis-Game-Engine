/*
 * Arm.hpp
 *
 *  Created on: 10 mars 2017
 *      Author: JulienCombattelli
 */

#ifndef GAMETEST_PHYSICS_ARM_HPP_
#define GAMETEST_PHYSICS_ARM_HPP_

#include <MUL/SFE/ConnectedRodShape.hpp>

namespace game
{

class Arm
{
public:
	mul::sfe::ConnectedRodShape shape;
	sf::Transform transform;

	Arm(int radius, int length) : shape(radius,length) {}
};

} // namespace mge

#endif /* GAMETEST_PHYSICS_ARM_HPP_ */
