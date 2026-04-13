#include <iostream>
#include <cstdint>
#include <sstream>
#include <memory>
#include <charconv>
// #include "includes/Controller.hpp"
using namespace std;

class IClass1
{
public:
    virtual void IClass1M() = 0;
};
class IClass2
{
public:
    virtual void IClass2M() = 0;
};

class Qqq : public IClass1, public IClass2
{
public:
    void IClass1M(){cout << "IClass1M\n";}
    void IClass2M(){cout << "IClass2M\n";}
};


int main() {
    uint32_t clr;
    clr = 0xff0000;
    std::cout << 2 << "\n";

    return 0;
}
