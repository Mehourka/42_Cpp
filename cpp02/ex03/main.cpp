#include "Fixed.hpp"
#include "Point.hpp"

#define Log(x) std::cout << (x) << std::endl

int main( void ) {

    Log("This is BSP: \n\n");
    Point o = Point(0.0, 0.0);
    Point x = Point(1.67, 1.42);

    Log(o);
    Log(x);

}