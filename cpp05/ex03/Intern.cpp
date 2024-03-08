#include "Intern.hpp"

Intern::Intern()
{
    Log("[ Intern ] Default Constructor");
}

Intern::Intern(const Intern &other)
{
    Log("[ Intern ] Copy Constructor");
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    Log("[ Intern ] Assigment Operator");
    // Copy Here
    (void) other;
    return *this;
}

Intern::~Intern()
{
    Log("[ Intern ] Default Destructor");
}



AForm *Intern::makeForm(const std::string &type, const std::string &target)
{
        formCreatorFnc formFnc = findFormFnc(type);
        return (this->*formFnc)(target);
}

formCreatorFnc Intern::findFormFnc(const std::string &type)
{
    const int SIZE = 3;
    std::string keys[SIZE] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon",
    };

    formCreatorFnc values[SIZE] = {
        &Intern::createSCF,
        &Intern::createRRF,
        &Intern::createPPF
    };

    for (int i = 0; i < SIZE; i++)
    {
        if (keys[i] == type)
            return values[i];
    }
    throw FormNotFoundException();
}

AForm *Intern::createSCF(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRRF(const std::string &target)
{

    return new RobotomyRequestForm(target);
}

AForm *Intern::createPPF(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return "FormNotFoundException: Intern unable to find requested form";
}