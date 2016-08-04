//============================================================================
// Name        : Functional.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It is an extension of the standard functional library
//============================================================================

#ifndef FUNCTIONAL_HPP_
#define FUNCTIONAL_HPP_

#include <functional>

namespace mul
{

template <class Functor, class... Args>
void call(Functor&& f, Args&&... args)
{
	f(std::forward<Args>(args)...);
}

} // namespace mul

#endif // FUNCTIONNAL_HPP_
