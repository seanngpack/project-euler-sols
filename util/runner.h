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
      auto& manager = ScopedTimer::get_manager();      
      auto times = manager.get_times();            
      std::chrono::nanoseconds sum{0};                               
      int num = times.size() - num_iterations;      
      for (int i = times.size()-1; i >= num; i--)                            
        sum += times[i];      
        
      std::cout << "Average time is: " << (sum/num_iterations).count() << " nanoseconds" << std::endl;
      std::cout << "Average time is: " << (sum/num_iterations).count() * 1e-6 << " milliseconds" << std::endl;
      std::cout << "Average time is: " << (sum/num_iterations).count() * 1e-9 << " seconds" << std::endl;
    }

  };

}
