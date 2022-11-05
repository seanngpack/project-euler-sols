#include "../util/runner.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

bool is_palindrome(int num)
{
  int num_copy = num;
  int reverse = 0;
  int dig;

  while (num > 0)
  {
    dig = num % 10;               // mod 10 gets the last digit
    reverse = reverse * 10 + dig; // build the reverse int up
    num /= 10;                    // div 10 removes the last digit
  }

  if (num_copy == reverse)
    return true;
  return false;
}

/**
* A palindromic number reads the same both ways. The largest palindrome made from the
* product of two 2-digit numbers is 9009 = 91 × 99.

  Find the largest palindrome made from the product of two 3-digit numbers.
*/
int largest_palindrome_product()
{
  int greatest = 0;
  for (int i = 100; i < 1000; ++i)
  {
    for (int j = 100; j < 1000; ++j)
    {
      int prod = i * j;
      if (prod > greatest && is_palindrome(prod))
        greatest = prod;
    }
  }

  return greatest;
}

int main()
{
  timer::Runner runner;
  runner.run(largest_palindrome_product, 10);
  int ans = largest_palindrome_product();
  cout << "answer is: " << ans << endl;
  return 0;
}
