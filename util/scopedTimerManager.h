#pragma once

#include <chrono>
#include <vector>

namespace timer
{
  class ScopedTimerManager
  {
  public:
    void add_time(std::chrono::nanoseconds &time_wall, clock_t &time_cpu)
    {
      times_wall.push_back(time_wall);
      times_cpu.push_back(time_cpu);
    }

    std::vector<std::chrono::nanoseconds> get_times_wall()
    {
      return times_wall;
    }

    std::vector<clock_t> get_times_cpu()
    {
      return times_cpu;
    }

  private:
    std::vector<std::chrono::nanoseconds> times_wall;
    std::vector<clock_t> times_cpu;
  };
} // namespace timer