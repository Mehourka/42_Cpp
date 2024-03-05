#include <iostream>
#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(void)
{

    // Do not change: not in try block
    Bureaucrat pew = Bureaucrat("Pew", 43);
    Bureaucrat pie = Bureaucrat("Pie", 41);

    // AForm form = AForm("A-42", 42, 42);

    try
    {
        LogInfoC("Try block start: \n", YELLOW);
        std::cout << pie << pew << std::endl;
        std::cout << form << std::endl;

        pew.signForm(form);
        pie.signForm(form);
        // Form over("Over", 151, 151); // Throws exception
        // Form under("Under", 0, 0); // Throws exception
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
