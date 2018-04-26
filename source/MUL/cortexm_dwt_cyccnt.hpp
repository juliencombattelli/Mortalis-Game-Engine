/*
 * cortexm_dwt_cyccnt.h
 *
 *  Created on: Apr 26, 2018
 *      Author: jucom
 */

#ifndef BENCHMARK_TOOL_CORTEXM_DWT_CYCCNT_H_
#define BENCHMARK_TOOL_CORTEXM_DWT_CYCCNT_H_

#include "Bench.hpp"

//#define MUL_CORTEX_M3
#define MUL_CORTEX_M4
//#define MUL_CORTEX_M7

#if defined(MUL_CORTEX_M3)
#include "core_cm3.h"
#elif defined(MUL_CORTEX_M4)
#include "core_cm4.h"
#elif defined(MUL_CORTEX_M7)
#include "core_cm7.h"
#else
#warning "This library require a core Cortex M3, M4 or M7."
#endif

#if defined(MUL_CORTEX_M3) || defined(MUL_CORTEX_M4) || defined(MUL_CORTEX_M7)
#if defined(MUL_CORTEX_M3)
struct cortexm3_dwt_cyccnt
#elif defined(MUL_CORTEX_M4)
struct cortexm4_dwt_cyccnt
#elif defined(MUL_CORTEX_M7)
struct cortexm7_dwt_cyccnt
#endif
{
	using unit = uint32_t;

	static void init()
	{
		CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
		DWT->CYCCNT = 0;
		DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
	}

	static unit get_time() { return DWT->CYCCNT; }
};
#endif

#endif /* BENCHMARK_TOOL_CORTEXM_DWT_CYCCNT_H_ */
