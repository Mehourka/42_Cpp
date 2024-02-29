#include "Fixed.hpp"
#include "Point.hpp"

#define PT_NUM 8
#define COUT_GREEN "\033[32m"
#define COUT_YELLOW "\033[33m"
#define COUT_WHITE "\033[37m"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main(void)
{
    // Triangle vertices
    Point a = Point(0.0, 0.0);
    Point b = Point(3.0, 0.0);
    Point c = Point(0.0, 3.0);


    std::cout <<"Starting BSP:\n"
	<<"Checking if points are inside triangle:\n"
	<<a << b << c << "\n" << std::endl;

    // Creating test points
    Point points[PT_NUM] = {
        Point(1, 1), Point(1.4, 1.4), Point(2, 0.8), // Inside
        Point(1.6, 1.6), Point(-1, -1), // Outside
        a, b, c // Vertexes are "Outside"
    };
    Point x;
    for (int i = 0; i < PT_NUM; i++)
    {
        x = points[i];
        std::cout << " - ";
        if (bsp(a, b, c, x))
        {
            std::cout << COUT_GREEN << x << COUT_WHITE
            << "is Inside the triangle." << "\033[0m";
        } else {
            std::cout << COUT_YELLOW << x << COUT_WHITE
            << "is Outside the triangle" << "\033[0m";
        }
        std::cout <<std::endl;


    }
}
