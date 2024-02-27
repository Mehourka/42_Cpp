#include "Fixed.hpp"

#define Log(x) std::cout << x << std::endl

int main(void)
{
    Fixed a;
    Fixed b(a);
    Fixed c;

    a.setRawBits(4);
    c.setRawBits(69);

    c = b;

    b.setRawBits(2);

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}
