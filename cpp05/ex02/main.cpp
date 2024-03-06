#include <iostream>
#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{

    // Do not change: not in try block
    Bureaucrat pippin = Bureaucrat("Pippin", 140);
    Bureaucrat aragorn = Bureaucrat("Aragorn", 25);
    Bureaucrat gandalf = Bureaucrat("Gandalf", 5);


    RobotomyRequestForm robotomize("Melon Eusk");
    PresidentialPardonForm pardon("Emon Lusk");
    // PresidentialPardonForm pardon("Elos Munk");

    try
    {

        LogInfoC("Try block start: \n", YELLOW);
        std::cout << gandalf << aragorn << pippin << std::endl;

        std::cout << "\n" << robotomize << std::endl;

        gandalf.executeForm(robotomize); // Cant execute unsigned form
        pippin.signForm(robotomize); // Grade insuffisant
        aragorn.signForm(robotomize);
        gandalf.executeForm(robotomize);

        std::cout << "\n\n" << pardon << std::endl;
        aragorn.signForm(pardon);
        aragorn.executeForm(pardon);
        gandalf.executeForm(pardon);


        // std::cout << "\n" << pardon << std::endl;
        // Form over("Over", 151, 151); // Throws exception
        // Form under("Under", 0, 0); // Throws exception
        LogInfoC("Try block Complete !\n", GREEN);
    }
    catch (const std::exception &e)
    {
        LogErr("Caught exception");
        LogErr(e.what());
    }



    return (0);
}
