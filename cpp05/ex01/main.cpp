#include <iostream>
#include "Common.hpp"
#include "Bureaucrat.hpp"

int main(void)
{

    Bureaucrat pie = Bureaucrat("Pie", 41);
    Bureaucrat pew = Bureaucrat("Pew", 150);

    try
    {
        LogInfoC("Try block start: \n", YELLOW);
        std::cout << pie << pew << std::endl;
        pie.upgrade();
        // pew.upgrade();                // Throws exception
        // Bureaucrat over("Over", 151); // Throws exception
        // Bureaucrat under("Under", 0); // Throws exception
        pew.downgrade();
        LogInfoC("Try block Complete !\n", GREEN);
    }
    catch (const std::exception &e)
    {
        LogErr("Caught exception");
        LogErr(e.what());
    }

    std::cout << pie << pew << std::endl;

    return (0);
}
