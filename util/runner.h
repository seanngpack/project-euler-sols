#pragma once

#include "scopedTimer.h"
#include "scopedTimerManager.h"
#include <functional>
#include <vector>

namespace timer
{
  // runs functions and times them
  class Runner
  {
  public:
    Runner() = default;

    template <typename T, typename Function>
    void run(Function func, T func_arg, int num_iterations)
    {
      for (int i = 0; i < num_iterations; ++i)
      {
        ScopedTimer timer;
        func(func_arg);
      }

      calc_average(num_iterations);
    }

    template <typename Function>
    void run(Function func, int num_iterations)
    {
      for (int i = 0; i < num_iterations; ++i)
      {
        ScopedTimer timer;
        func();
      }

      calc_average(num_iterations);
    }

  private:
    void calc_average(int num_iterations)
    {
      auto &manager = ScopedTimer::get_manager();
      auto times_wall = manager.get_times_wall();
      auto times_cpu = manager.get_times_cpu();
      std::chrono::nanoseconds sum_wall{0};
      double sum_cpu = 0.0;

      int num = times_cpu.size() - num_iterations;      
      for (int i = times_wall.size() - 1; i >= num; i--)
      {
        sum_wall += times_wall[i];
        sum_cpu += (double)times_cpu[i]/CLOCKS_PER_SEC; // prevent overflow
      }
        
      std::cout << "Average cputime is: " << std::fixed << sum_cpu / num_iterations * 1e9 << " nanoseconds" << std::endl;
      std::cout << "Average cputime is: " << sum_cpu / num_iterations * 1e3 << " milliseconds" << std::endl;
      std::cout << "Average cputime is: " << sum_cpu / num_iterations << " seconds" << std::endl;
      std::cout << "Average walltime is: " << (sum_wall / num_iterations).count() << " nanoseconds" << std::endl;
      std::cout << "Average walltime is: " << (sum_wall / num_iterations).count() * 1e-6 << " milliseconds" << std::endl;
      std::cout << "Average walltime is: " << (sum_wall / num_iterations).count() * 1e-9 << " seconds" << std::endl;
    }
  };

}
