#include "../util/runner.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

void helper(long num, int &largest)
{
  bool triggered = false;
  for (long i = 2; i <= ceil(num / 2); i++)
  {
    if (num % i == 0)
    {
      triggered = true;
      long quotient = num / i;
      // cout << "num: " << num << " quotient: " << quotient << " i: " << i <<
      // endl;
      helper(quotient, largest);
      helper(i, largest);
      break;
    }
  }
  if (!triggered && num > largest)
    largest = num;
}

/**
* The prime factors of 13195 are 5, 7, 13 and 29.

 What is the largest prime factor of the number 600851475143 ?
*/
long largest_prime_factor(long num)
{
  //     18
  //  /  \  \  \
  // 2  9   3  6
  //   / \    / \
  //  3  3    3  2
  // i came up with two distinct trees. this tells me one i find a match for
  // a prime factor, then just go deeper instead of exploring other options
  // make sure to check up to num / 2 for prime factor
  int largest = 0;
  helper(num, largest);
  return largest;
}

int main()
{
  int ans;
  timer::Runner runner;
  runner.run(largest_prime_factor, 600851475143, 10);
  cout << "answer is: " << ans << endl;
  return 0;
}
