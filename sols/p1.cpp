#include "../util/runner.h"
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/**
 * If we list all the natural numbers below 10 that are multiples of 3 or 5, we
 get 3, 5, 6 and 9.
 * The sum of these multiples is 23.

 * Find the sum of all the multiples of 3 or 5 below 1000.
*/
int sum_multiples()
{
  int running = 0;
  for (int i = 3; i < 1000; ++i)
  {
    if (i % 3 == 0 || i % 5 == 0)
      running += i;
  }
  return running;
}

int main()
{
  timer::Runner runner;
  runner.run(sum_multiples, 10);
  int ans = sum_multiples();
  cout << ans << endl;
  return 0;
}
