#include <iostream>
#include <cstdint>
#include <sstream>
#include <memory>
#include <charconv>
// #include "includes/Controller.hpp"

using namespace std;

bool IsValidNumber(const std::string& input, double& num)
{
    if (input.empty()) return false;
    auto [ptr, err] = std::from_chars(input.data(), input.data() + input.size(), num);
    return err == std::errc{} && ptr == input.data() + input.size();
}

int main() {
    uint32_t x = 0x00aaff;
    std::cout << std::hex << x << "\n";

    double d = 2;
    int i = 13;
    std::cout << (i >> 1) << "\n";

    double n;
    if(IsValidNumber("-56.789", n)) cout << "VALID: " << n << endl;;

    return 0;
}
