#include "Generator.hpp"

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    set<int> primes{};
    primes.insert(2);
    if (upperBound == 2)
    {
        return primes;
    }

    vector<bool> isPrime(upperBound + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (size_t i = 1; i <= upperBound; i += 2)
    {
        if (isPrime[i])
        {
            for (size_t step = i * i; step <= upperBound; step += i * 2)
            {
                isPrime[step] = false;
            }
        }
    }

    for (size_t i = 3; i <= upperBound; i += 2)
    {
        if (isPrime[i])
            primes.insert(i);
    }
    return primes;
}
