#include "../util/runner.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

/**
SOLUTION USING MATH
Take a sub problem: what is the smallest + number that is evenly divisble by 3,4,6?
write the numbers as primes:
3 = 3 * 1
4 = 2 * 2
6 = 2 * 3

since the num is divisible by 3, 3 must be a factor
num = 3 * ?

Since the num is divisible by 4, and 4 has 2 2's:
num = 3 * 2 * 2 * ?

Since the num is divisible by 6, and we already have a 2 and a 3 in our factors, dont add anything
num = 3 * 2 * 2

num = 12

Do the same process with nums 1->20 to get our answer.
**/

/**
* 2520 is the smallest number that can be divided by each of the
* numbers from 1 to 10 without any remainder.

  What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
long smallest_multiple()
{
  long num = 2520;
  while (true)
  {
    bool flag = true;
    for (long i = 2; i <= 20; ++i)
    {
      if (num % i != 0)
      {
        flag = false;
        break;
      }
    }
    if (flag)
      return num;
    num++;
  }
}

int main()
{
  timer::Runner runner;
  runner.run(smallest_multiple, 1);
  int ans = smallest_multiple();
  cout << "answer is: " << ans << endl;
  return 0;
}
