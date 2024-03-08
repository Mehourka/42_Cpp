#include <iostream>
#include "Common.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{

    // Do not change: not in try block
    Bureaucrat pippin = Bureaucrat("Pippin", 140);
    Bureaucrat aragorn = Bureaucrat("Aragorn", 25);
    Bureaucrat gandalf = Bureaucrat("Gandalf", 5);

    // RobotomyRequestForm robotomize("Melon Eusk");
    // PresidentialPardonForm pardon("Emon Lusk");
    // ShrubberyCreationForm plants("Elos Munk");

    Intern tim;
    AForm* rrf = NULL;
    AForm* ppf = NULL;
    AForm* scf = NULL;

    try
    {
        rrf = tim.makeForm("shrubbery creation", "Melon Eusk");
        ppf = tim.makeForm("robotomy request", "Emon Lusk");
        scf = tim.makeForm("presidential pardon", "Elos Munk");

        // Throws error if form does not exist
        // tim.makeForm("made-up form", "Elos Munk");


        LogInfoC("Try block start: \n", YELLOW);
        std::cout << gandalf << aragorn << pippin << std::endl;

        std::cout << "\n"
                  << *scf << std::endl;
        pippin.signForm(*scf);
        pippin.executeForm(*scf);
        aragorn.executeForm(*scf);

        std::cout << "\n"
                  << *rrf << std::endl;
        gandalf.executeForm(*rrf); // Cant execute unsigned form
        pippin.signForm(*rrf);     // Grade insuffisant
        aragorn.signForm(*rrf);
        gandalf.executeForm(*rrf);

        std::cout << "\n"
                  << *ppf << std::endl;
        aragorn.signForm(*ppf);
        aragorn.executeForm(*ppf);
        gandalf.executeForm(*ppf);

        LogInfoC("Try block Complete !\n", GREEN);
    }
    catch (const std::exception &e)
    {
        LogErr("[ Caught exception ]");
        LogErr(e.what());
    }
    delete rrf;
    delete ppf;
    delete scf;
    return (0);
}
