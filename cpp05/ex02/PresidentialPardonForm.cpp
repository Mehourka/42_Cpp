#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential pardon form", 25, 5)
{
    Log("[ PresidentialPardonForm ] Default Constructor");
}

PresidentialPardonForm::PresidentialPardonForm(const string &target)
    : AForm("Presidential pardon form", 25, 5)
{
    Log("[ PresidentialPardonForm ] Default Constructor");
    setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm("Presidential pardon form", 25, 5)
{
    Log("[ PresidentialPardonForm ] Copy Constructor");
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    Log("[ PresidentialPardonForm ] Assigment Operator");
    // Grades and name are const
    this->setTarget(other.getTarget());
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    Log("[ PresidentialPardonForm ] Default Destructor");
}


void PresidentialPardonForm::formAction() const
{
    std::cout << this->getTarget()
              << " à été pardonnée par Zaphod Beeblebrox."
              << std::endl;
}

