//============================================================================
// Name        : Memory.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 22 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It is an extension of the standard memory library
//============================================================================

#ifndef MEMORY_HPP_
#define MEMORY_HPP_

#if __cplusplus < 201103L
  #error This library needs at least a C++11 compliant compiler
#endif

#include <memory>

namespace mul
{

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
#if __cplusplus < 201402L
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
#else
	return std::make_unique<T>(std::forward<Args>(args)...);
#endif
}

} // namespace mul

#endif // MEMORY_HPP_
