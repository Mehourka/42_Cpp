#pragma once
#include "Common.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern;

typedef AForm *(Intern::*formCreatorFnc)(const std::string &);

class Intern
{
public:
    Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);
    ~Intern();

    AForm *makeForm(const std::string &type, const std::string &target);

private:
    AForm *createSCF(const std::string &target);
    AForm *createRRF(const std::string &target);
    AForm *createPPF(const std::string &target);
    formCreatorFnc findFormFnc(const std::string &type);

    class FormNotFoundException: public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};


