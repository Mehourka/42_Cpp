#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy request form", 72, 45)
{
    Log("[ RobotomyRequestForm ] Default Constructor");
}

RobotomyRequestForm::RobotomyRequestForm(const string &target)
    : AForm("Robotomy request form", 72, 45)
{
    Log("[ RobotomyRequestForm ] Default Constructor");
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm("Robotomy request form", 72, 45)
{
    Log("[ RobotomyRequestForm ] Copy Constructor");
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    Log("[ RobotomyRequestForm ] Assigment Operator");
    // Grades and name are const
    this->setTarget(other.getTarget());
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    Log("[ RobotomyRequestForm ] Default Destructor");
}

void RobotomyRequestForm::formAction() const
{
    std::cout << " * Bzzzzzzzzzzzz *" << std::endl;
    srand(time(0));
    if (rand() % 2 == 1)
    {
        std::cout << getTarget() << " a été robotomisée avec succès! 🤖";
    }
    else
    {
        std::cout << "La robotomisation de " << getTarget() << " à échoué. 💀";
    }
    std::cout << std::endl;
}
