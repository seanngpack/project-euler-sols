#pragma once

#include "scopedTimerManager.h"
#include <chrono>
#include <iostream>

namespace timer
{
  class ScopedTimer
  {
  public:
    ScopedTimer() : begin_wall(std::chrono::high_resolution_clock::now()), begin_cpu(std::clock()) {}

    ~ScopedTimer()
    {
      auto end_wall = std::chrono::high_resolution_clock::now();
      auto end_cpu = std::clock();
      auto elapsed_wall =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end_wall - begin_wall);
      auto elapsed_cpu = end_cpu - begin_cpu;

      get_manager().add_time(elapsed_wall, elapsed_cpu);
    }

    static ScopedTimerManager &get_manager()
    {
      static ScopedTimerManager manager;
      // std::cout << "manager addr in scopedtimer gerManager: " << &manager << std::endl;
      return manager;
    }

  private:
    std::chrono::steady_clock::time_point begin_wall;
    std::clock_t begin_cpu;
  };
} // namespace Timer
