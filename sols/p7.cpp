#include "../util/runner.h"
#include <iomanip>
#include <iostream>
#include <math.h>
#include <memory>
#include <vector>

using namespace std;

//Use Prime number theoreom to get upper bound of a guess to feed into sieve of erat...
int get_upper(int n)
{ 
  // log base e
  return n * (log(n) + log(log(n)));
}

/**
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/
long prime_10001st(int n)
{
  // let's NOT use trial division like problem 3. I'm gonna implement sieve of Eratosthenes...
  // and gonna use prime number theoreom (PNT) to get an upper bound of a guess

  int upper = get_upper(n);

  vector<bool> primes(upper+1, true);
  for (int p = 2; p * p <= upper; p++)  
    if (primes[p])    
      for (int i = p*p; i <= upper; i+=p)      
        primes[i] = false;

  int count = 0;
  int p = 2;
  while (count < 10001)
  {
    if (primes[p])
    {
      // std::cout << p << std::endl;
      count++;
    }
    p++;
  }

  return p-1;
}

int main()
{
  timer::Runner runner;
  runner.run(prime_10001st, 10001, 1);
  long ans = prime_10001st(10001);
  cout << "answer is: " << ans << endl;
  return 0;
}
