#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    Log("[ Bureaucrat ] Default Constructor");
}

Bureaucrat::Bureaucrat(const string &name, const int &grade) : _name(name)
{
    Log("[ Bureaucrat ] Name/Grade Constructor");
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
    Log("[ Bureaucrat ] Copy Constructor");
    setGrade(other.getGrade());
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    Log("[ Bureaucrat ] Assigment Operator");

    this->setGrade(other.getGrade());
    // TODO : Copy name ?
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    Log("[ Bureaucrat ] Default Destructor");
}

void Bureaucrat::setGrade(const int &val)
{
    if (val > Bureaucrat::MaxGrade)
        throw Bureaucrat::GradeTooHighException();
    if (val < Bureaucrat::MinGrade)
        throw Bureaucrat::GradeTooLowException();

    _grade = val;
}

string Bureaucrat::getName() const
{
    return (_name);
}

int Bureaucrat::getGrade() const
{
    return (_grade);
}

void Bureaucrat::upgrade()
{
    setGrade(getGrade() + 1);
}

void Bureaucrat::downgrade()
{
    setGrade(getGrade() - 1);
}

void Bureaucrat::signForm(AForm &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " signed " << form.getName() << std::endl;
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cout << getName() << " couldn't signe " << form.getName()
                  << " because of insuficient grade." << std::endl;
    }
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException: Grade is higher than max: 150");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException: Grade is lower than min: 1");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName()
      << ", bureaucrat grade " << b.getGrade() << std::endl;

    return o;
}