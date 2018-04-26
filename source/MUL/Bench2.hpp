/*
 * Bench.hpp
 *
 *  Created on: Apr 26, 2018
 *      Author: jucom
 */

#ifndef BENCH2_HPP_
#define BENCH2_HPP_

//#define MUL_BENCHMARK_USE_DEFAULT_CPP_LOGGER
#define MUL_BENCHMARK_USE_DEFAULT_C_LOGGER

#include <string>
#include <type_traits>

#if defined(MUL_BENCHMARK_USE_DEFAULT_CPP_LOGGER)
#include <iostream>
#elif defined(MUL_BENCHMARK_USE_DEFAULT_C_LOGGER)
#include <cstdio>
#endif

template<typename TTimer>
class Bench
{
public:

	using time_unit = typename TTimer::unit;
	static_assert(std::is_arithmetic<time_unit>::value, "TTimer::unit must be an arithmetic type.");

	struct Stat
	{
		time_unit min;
		time_unit max;
		time_unit average;
	};

	struct logger_start_tag{};
	struct logger_end_tag{};

#if defined(MUL_BENCHMARK_USE_DEFAULT_CPP_LOGGER)

	class DefaultStartLogger
	{
		using category = logger_start_tag;

		void operator()(const std::string& name, unsigned iteration)
		{
			std::cout << "Running bench \"" << name << "\"...\r\n";
		}
	};

	class DefaultEndLogger
	{
		using category = logger_end_tag;

		void operator()(const std::string& name, unsigned iteration, const Stat& stat)
		{
			std::cout << "Bench \"" << name << "\" finished.\r\n";
			std::cout << "Bench \"" << name << "\" statistics (over" << iteration << "iterations):\r\n";
			std::cout << "  min:     " << stat.min 		<< " ticks,\r\n";
			std::cout << "  max:     " << stat.max 		<< " ticks,\r\n";
			std::cout << "  average: " << stat.average 	<< " ticks.\r\n";
			std::cout << "\r\n";
		}
	};

	template<typename TF, typename... TArgs>
	Stat operator()(const std::string& name, unsigned iteration, TF&& functor, TArgs&&... args)
	{
		return _bench_and_log(name, iteration, DefaultStartLogger{}, DefaultEndLogger{}, functor,  std::forward(args)...);
	}

#elif defined(MUL_BENCHMARK_USE_DEFAULT_C_LOGGER)

	class DefaultStartLogger
	{
		using category = logger_start_tag;

		void operator()(const std::string& name, unsigned iteration)
		{
			printf("Running bench \"%s\"...\r\n", name.c_str());
		}
	};

	class DefaultEndLogger
	{
		using category = logger_end_tag;

		void operator()(const std::string& name, unsigned iteration, const Stat& stat)
		{
			printf("Bench \"%s\" finished.\r\n", name.c_str());
			printf("Bench \"%s\" statistics (over %u iterations):\r\n", name.c_str(), iteration);
			printf("  min:     %i ticks,\r\n", stat.min);
			printf("  max:     %i ticks,\r\n", stat.max);
			printf("  average: %i ticks.\r\n", stat.average);
			printf("\r\n");
		}
	};

	template<typename TF, typename... TArgs>
	Stat operator()(const std::string& name, unsigned iteration, TF&& functor, TArgs&&... args)
	{
		return _bench_and_log(name, iteration, DefaultStartLogger{}, DefaultEndLogger{}, functor,  std::forward(args)...);
	}

#endif

	template<typename TF, typename... TArgs>
	Stat operator()(unsigned iteration, TF&& functor, TArgs&&... args)
	{
		return _bench(functor, std::forward(args)...);
	}

	template<typename Logger, typename TF, typename... TArgs>
	Stat operator()(const std::string& name, unsigned iteration, Logger&& logger, TF&& functor, TArgs&&... args)
	{
		typename Logger::category logger_category;
		return _bench_and_log(name, iteration, logger, logger_category, functor,  std::forward(args)...);
	}

	template<typename StartLogger, typename EndLogger, typename TF, typename... TArgs>
	Stat operator()(const std::string& name, unsigned iteration, StartLogger&& startLogger, EndLogger&& endLogger, TF&& functor, TArgs&&... args)
	{
		return _bench_and_log(name, iteration, startLogger, endLogger, functor,  std::forward(args)...);
	}

private:

	template<typename TF, typename... TArgs>
	Stat _bench(unsigned iteration, TF&& functor, TArgs&&... args)
	{
		Stat stat;
		stat.min = std::numeric_limits<decltype(stat.min)>::max();
		stat.max = std::numeric_limits<decltype(stat.max)>::min();
		stat.average = 0;

		for(unsigned i = 0; i < iteration; i++)
		{
			auto tbegin = m_timer.get_time();
			functor(std::forward(args)...);
			auto tend = m_timer.get_time();

			auto tresult = tend - tbegin;

			stat.max = std::max(stat.max, tresult);
			stat.min = std::min(stat.min, tresult);
			stat.average += tresult;
		}
		stat.average /= iteration;

		return stat;
	}

	template<typename Logger, typename TF, typename... TArgs>
	Stat _bench_and_log(const std::string& name, unsigned iteration, Logger&& startLogger, logger_start_tag, TF&& functor, TArgs&&... args)
	{
		startLogger(name, iteration);
		return _bench(functor, std::forward(args)...);
	}

	template<typename Logger, typename TF, typename... TArgs>
	Stat _bench_and_log(const std::string& name, unsigned iteration, Logger&& startLogger, logger_end_tag, TF&& functor, TArgs&&... args)
	{
		Stat stat = _bench(functor, std::forward(args)...);
		endLogger(name, iteration, stat);
		return stat;
	}

	template<typename StartLogger, typename EndLogger, typename TF, typename... TArgs>
	Stat _bench_and_log(const std::string& name, unsigned iteration, StartLogger&& startLogger, EndLogger&& endLogger, TF&& functor, TArgs&&... args)
	{
		Stat stat;
		startLogger(name, iteration);
		stat = _bench(functor, std::forward(args)...);
		endLogger(name, iteration, stat);
		return stat;
	}

	TTimer m_timer;
};

#endif /* BENCH2_HPP_ */
