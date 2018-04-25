//============================================================================
// Name        : Bench.hpp
// Author      : Julien Combattelli
// EMail       : julien.combattelli@gmail.com
// Date        : 25 apr. 2018
// Version     : 1.0.0
// Copyright   : This file is part of MUL project which is released under
//               MIT license. See file LICENSE.txt for full license details
// Description : Provide some tools to benchmark C++ code (only for STM32F4)
//============================================================================

#ifndef MUL_BENCH_HPP_
#define MUL_BENCH_HPP_

#if __cplusplus < 201103L
#error This library needs at least a C++11 compliant compiler
#endif

#include "stm32f4xx.h"
#include <cstdio>
#include <utility>
#include <string>
#include <limits>

#ifdef __GNUC__
#define DO_NOT_OPTIMIZE __attribute__((optimize("O0")))
#else
#define DO_NOT_OPTIMIZE
#endif

namespace mul
{

template<typename F, typename... FArgs>
void bench(const std::string& name, unsigned iteration, F&& functor, FArgs&&... fargs) noexcept
{
    if(iteration == 0)
    {
        printf("Cannot run bench \"%s\".\r\n", name.c_str());
        printf("  %s:%i: wrong argument: \'iteration\' must be not null.\r\n", __FILE__, __LINE__);
        printf("\r\n");
        return;
    }

    printf("Running bench \"%s\"...\r\n", name.c_str());

    int min = std::numeric_limits<decltype(min)>::max();
    int max = std::numeric_limits<decltype(min)>::min();
    int average = 0;

    for(unsigned i = 0; i < iteration; i++)
    {
        int tbegin = DWT->CYCCNT;
        functor(std::forward(fargs)...);
        int tend = DWT->CYCCNT;

        int tresult = tend - tbegin;

        max = std::max(max, tresult);
        min = std::min(min, tresult);
        average += tresult;
    }
    average /= iteration;

    std::string itstr = "iteration";
    if(iteration > 1)
        itstr += "s";

    printf("Bench \"%s\" finished.\r\n", name.c_str());
    printf("Bench \"%s\" statistics (over %u %s):\r\n", name.c_str(), iteration, itstr.c_str());
    printf("  min:     %i ticks,\r\n", min);
    printf("  max:     %i ticks,\r\n", max);
    printf("  average: %i ticks.\r\n", average);
    printf("\r\n");
}

} // namespace mul

#endif // MUL_BENCH_HPP_
