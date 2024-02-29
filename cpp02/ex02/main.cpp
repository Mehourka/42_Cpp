#include "Fixed.hpp"

#define Log(x) std::cout << (x) << std::endl

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << "\n";
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;
    Fixed c = Fixed::max(a, b);
    std::cout << "\n";

    std::cout << "3 / 2 = " << Fixed(3) / Fixed(2) << std::endl;
    std::cout << "1 / 3 = " << Fixed(1) / Fixed(3) << std::endl;
    std::cout << "3 - 6 = " << Fixed(3) - Fixed(6) << std::endl;
    std::cout << "30 + 12 = " << Fixed(30) + Fixed(12) << std::endl;
    std::cout << "\n" << std::endl;
    
    return 0;
}
