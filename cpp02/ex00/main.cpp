#include <iostream>
#include <string>

#include "Fixed.hpp"

#define Log(x) std::cout << x << std::endl


int main(void)
{
    Fixed first(5);
    Fixed s(10);
    Fixed second = s;


    Fixed sum = first + second;

    Log(first + second + Fixed(2));
}
