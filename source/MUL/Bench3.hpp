/*
 * Bench.hpp
 *
 *  Created on: Apr 26, 2018
 *      Author: jucom
 */

#ifndef BENCH3_HPP_
#define BENCH3_HPP_

#include <string>
#include <type_traits>
#include <cstdio>

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

	struct ILogger
	{
		virtual ~ILogger() = default;
		virtual void logStart(const std::string& name, unsigned iterations) = 0;
		virtual void logEnd(const std::string& name, unsigned iterations, const Stat& stat) = 0;
	};

	struct PrintfLogger : public ILogger
	{
		void logStart(const std::string& name, unsigned iterations) override
		{
			printf("Running bench \"%s\"...\r\n", name.c_str());
		}

		void logEnd(const std::string& name, unsigned iteration, const Stat& stat) override
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
	Stat operator()(unsigned iteration, TF&& functor, TArgs&&... args)
	{
		return bench(functor, std::forward(args)...);
	}

	template<typename TF, typename... TArgs>
	Stat operator()(const std::string& name, unsigned iterations, TF&& functor, TArgs&&... args)
	{
		Stat stat;
		PrintfLogger logger;
		if(m_startlog_enabled)
			logger.logStart(name, iterations);
		stat = bench(iterations, functor,  std::forward(args)...);
		if(m_endlog_enabled)
			logger.logEnd(name, iterations, stat);
		return stat;
	}

	template<typename TF, typename... TArgs>
	Stat operator()(const std::string& name, unsigned iterations, ILogger& logger, TF&& functor, TArgs&&... args)
	{
		Stat stat;
		if(m_startlog_enabled)
			logger.logStart(name, iterations);
		stat = bench(iterations, functor,  std::forward(args)...);
		if(m_endlog_enabled)
			logger.logEnd(name, iterations, stat);
		return stat;
	}

	void enable_log(bool enabled) { enable_startlog(enabled); enable_endlog(enabled); }

	void enable_startlog(bool enabled) { m_startlog_enabled = enabled; }

	void enable_endlog(bool enabled) { m_endlog_enabled = enabled; }

private:

	template<typename TF, typename... TArgs>
	Stat bench(unsigned iteration, TF&& functor, TArgs&&... args)
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

	TTimer m_timer;
	bool m_startlog_enabled = false;
	bool m_endlog_enabled = false;
};

#endif /* BENCH3_HPP_ */
