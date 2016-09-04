//============================================================================
// Name        : main.cpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : Mar 1, 2016
// Version     : 1.0.0
// Copyright   : This file is part of MGE project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : Entry point of the program
//============================================================================

#include <MGE/Core/Engine/Engine.hpp>

int main()
{
	mge::Engine engine;
    mge::Status status = engine.run();

    return static_cast<int>(status);
}

