#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _attr(0)
{
    Log("[ Bureaucrat ] Default Constructor");
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _attr(0)
{
    Log("[ Bureaucrat ] Copy Constructor");
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    Log("[ Bureaucrat ] Assigment Operator");
    // Copy Here
    this->_attr = other._attr;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    Log("[ Bureaucrat ] Default Destructor");
}

void Bureaucrat::sayHello() const
{
    LogInfo("Hello from Bureaucrat");
}
