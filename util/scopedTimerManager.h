#pragma once

#include <chrono>
#include <vector>

namespace timer
{
  class ScopedTimerManager
  {
  public:
    void add_time(std::chrono::nanoseconds &time) { times.push_back(time); }

    std::vector<std::chrono::nanoseconds> get_times()
    {
      return times;
    }

  private:
    std::vector<std::chrono::nanoseconds> times;
  };
} // namespace timer