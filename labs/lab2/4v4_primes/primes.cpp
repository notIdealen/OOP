//
//g++
#include <iostream>
#include "includes/Generator.hpp"
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> primes{};
    int upperBound = stoi(argv[1]);
    if (upperBound < 2 || upperBound > 100'000'000)
    {
        cout << "INVALID upperBound\n";
        return 0;
    }
    auto start = chrono::high_resolution_clock::now();
    primes = GeneratePrimeNumbersSet(upperBound);
    for (int n : primes)
    {
        cout << n << ' ';
    }
    auto end = chrono::high_resolution_clock::now();
    cout << "\nPrimes number: " << primes.size() << endl;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    int sec = duration.count() / 1000;
    int ms = duration.count() - sec * 1000;
    std::cout << "Time: " << sec << "s " << ms << "ms\n";
    return 0;
}

//.\primes.exe 100000000 | Out-File data/out.txt
//.\primes.exe 100 | Out-File data/out.txt
