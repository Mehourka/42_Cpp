#include <iostream>
#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main(void)
{

    // Do not change: not in try block
    Bureaucrat low_grade = Bureaucrat("Pippin", 140);
    Bureaucrat mid_grade = Bureaucrat("Aragorn", 25);
    Bureaucrat high_grade = Bureaucrat("Gandalf", 5);

    RobotomyRequestForm robotomize("Melon Eusk");
    PresidentialPardonForm pardon("Emon Lusk");
    ShrubberyCreationForm plants("Elos Munk");

    try
    {

        LogInfoC("Try block start: \n", YELLOW);
        std::cout << high_grade << mid_grade << low_grade << std::endl;

        std::cout << "\n" << plants << std::endl;
        low_grade.signForm(plants);
        low_grade.executeForm(plants);      // Insufficient Grade 
        mid_grade.executeForm(plants);

        std::cout << "\n" << robotomize << std::endl;
        high_grade.executeForm(robotomize); // Cant execute unsigned form
        low_grade.signForm(robotomize);     // Insufficient Grade 
        mid_grade.signForm(robotomize);
        high_grade.executeForm(robotomize);

        std::cout << "\n" << pardon << std::endl;
        mid_grade.signForm(pardon);
        mid_grade.executeForm(pardon);      // Insufficient Grade 
        high_grade.executeForm(pardon);


        LogInfoC("Try block Complete !\n", GREEN);
    }
    catch (const std::exception &e)
    {
        LogErr("Caught exception");
        LogErr(e.what());
    }



    return (0);
}
