#include <iostream>
#include <cstdint>
#include <sstream>
#include <memory>

// #include "includes/Controller.hpp"

using namespace std;


int main() {
    uint32_t x = 0xffaaff;
    std::cout << std::hex << x << "\n";
    string s{"qwe "};
    s.append(to_string(x) + "\n");
    

    std::ostringstream oss;
    oss << std::hex << std::nouppercase << x;
    std::string outlineColor = oss.str();
    s.append("\toutline color=" + outlineColor).append("\n");
    std::cout << s << "\n";
    // std::cout << "num:>" << num2 << "<" << std::endl;
    if (nullptr)
        std::cout << "!!!!!!" << "\n";

    return 0;
}
