//
//g++
#include <iostream>
#include "includes/Generator.hpp"
#include <chrono>

using namespace std;

int main(int argc, char const *argv[])
{
    set<int> primes{};
    int upperBound;
    
    cout << "Enter upper bound in range [2, 100'000'000]:";
    cin >> upperBound;

    auto start = chrono::high_resolution_clock::now();
    
    primes = GeneratePrimeNumbersSet(upperBound);
    if (primes.empty()) cout << 'x';
    else for (int n : primes) cout << n << ' ';

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
