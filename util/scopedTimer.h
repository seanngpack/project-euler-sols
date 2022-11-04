#pragma once

#include "scopedTimerManager.h"
#include <chrono>
#include <iostream>

namespace timer
{
  class ScopedTimer
  {
  public:
    ScopedTimer() : begin(std::chrono::high_resolution_clock::now()) {}

    ~ScopedTimer()
    {
      auto end = std::chrono::high_resolution_clock::now();
      auto elapsed =
          std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

      get_manager().add_time(elapsed);
      // std::cout << "Function ran in: " << elapsed.count() * 1e-9 << " seconds"
      //           << std::endl;
      // std::cout << "Function ran in: " << elapsed.count() << " nanoseconds"
      //           << std::endl;
      // printf("Function ran in: %.3f seconds.\n", elapsed.count() * 1e-9);
      // printf("Function ran in: %lld nanoseconds.\n", elapsed.count());
    }

    static ScopedTimerManager &get_manager()
    {
      static ScopedTimerManager manager;
      // std::cout << "manager addr in scopedtimer gerManager: " << &manager << std::endl;
      return manager;
    }

  private:
    std::chrono::steady_clock::time_point begin;

  };
} // namespace Timer
