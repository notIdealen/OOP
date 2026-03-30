#include "Generator.hpp"

#include <iostream>
#include <vector>

using namespace std;

constexpr int MAX_UPPERBOUND = 100'000'000;
constexpr int MIN_UPPERBOUND = 2;

vector<bool> Sieve(int upperBound)
{
    vector<bool> sieve(upperBound + 1, true);
    sieve[0] = sieve[1] = false;
    for (size_t i = 1; i <= upperBound; i += 2)
    {
        if (sieve[i])
        {
            for (size_t step = i * i; step <= upperBound; step += i * 2)
            {
                sieve[step] = false;
            }
        }
    }
    return sieve;
}

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    set<int> primes{};
    if (upperBound < MIN_UPPERBOUND || upperBound > MAX_UPPERBOUND)
    {
        return primes;
    }

    primes.insert(2);
    if (upperBound == 2)
    {
        return primes;
    }

    auto sieve = Sieve(upperBound);

    for (size_t i = 3; i <= upperBound; i += 2)
    {
        if (sieve[i])
            primes.insert(i);
    }
    return primes;
}
