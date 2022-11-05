#include "../util/runner.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

// derived on paper
long sum_squares(int n)
{
  return ((1.0/3.0)*pow(n,3)) + ((1.0/2.0)*pow(n,2)) + ((1.0/6.0)*n);
}

// derived on paper
long square_of_sum(int n)
{
  return pow(((1.0/2.0)*pow(n,2)) + ((1.0/2.0)*n),2);
}

/**
* The sum of the squares of the first ten natural numbers is,
*        1^2 + 2^2 + .. + 10^2 - 385
* The square of the sum of the first ten natural numbers is,
*       (1 + 2 +...+ 10)^2 = 55^2 = 3025
* Hence the difference between the sum of the squares of the first ten natural 
* numbers and the square of the sum is 3025 - 385 = 2640

Find the difference between the sum of the squares of the first one hundred 
natural numbers and the square of the sum.
*/
long sum_square_difference(int num)
{
  // std::cout << sum_squares(4) << std::endl;
  // std::cout << square_of_sum(4) << std::endl;
  return square_of_sum(num) - sum_squares(num);
}

int main()
{
  timer::Runner runner;
  runner.run(sum_square_difference, 100, 1);
  long ans = sum_square_difference(100);
  cout << "answer is: " << ans << endl;
  return 0;
}
