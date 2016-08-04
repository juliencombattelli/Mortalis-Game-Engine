//============================================================================
// Name        : NonCopyable.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@hotmail.com
// Date		   : 27 jun. 2016
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : It provides a C++11 non copyable base class
//============================================================================

#ifndef MUL_NONCOPYABLE_HPP
#define MUL_NONCOPYABLE_HPP

#if __cplusplus < 201103L
  #error This library needs at least a C++11 compliant compiler
#endif

namespace mul
{

class NonCopyable 
{
protected:
	NonCopyable() = default;
	~NonCopyable() = default;

	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator=(const NonCopyable&) = delete;
};

}  // namespace mul

#endif // MUL_NONCOPYABLE_HPP
