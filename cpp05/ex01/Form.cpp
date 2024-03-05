#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : _name("Blank Paper"),
      _executionGrade(150),
      _signatureGrade(150),
      _isSigned(false)
{
    Log("[ Form ] Default Constructor");
}

Form::Form(const string &name, const int &executionGrade, const int &signatureGrade)
    : _name(name),
      _executionGrade(executionGrade),
      _signatureGrade(signatureGrade),
      _isSigned(false)
{
    Log("[ Form ] Name/Grade Constructor");
    validateGrade(_executionGrade);
    validateGrade(_signatureGrade);
}

Form::Form(const Form &other)
    : _name(other.getName()),
      _executionGrade(other.getExecutionGrade()),
      _signatureGrade(other.getSignatureGrade()),
      _isSigned(false)
{
    Log("[ Form ] Copy Constructor");
    validateGrade(_executionGrade);
    validateGrade(_signatureGrade);
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    Log("[ Form ] Assigment Operator");

    this->_isSigned = other._isSigned;
    // Grades an name are const
    return *this;
}

Form::~Form()
{
    Log("[ Form ] Default Destructor");
}

void Form::validateGrade(const int &val)
{
    if (val > Form::MaxGrade)
        throw Form::GradeTooHighException();
    if (val < Form::MinGrade)
        throw Form::GradeTooLowException();
}

string Form::getName() const
{
    return (_name);
}

int Form::getSignatureGrade() const
{
    return (_signatureGrade);
}

int Form::getExecutionGrade() const
{
    return (_executionGrade);
}

bool Form::getIsSigned() const
{
    return (_isSigned);
}

void Form::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > getSignatureGrade())
        throw Form::GradeTooLowException();
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException: Grade is higher than max: 1");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException: Grade is lower than expected");
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << form.getName()
      << ", form signature grade " << form.getSignatureGrade()
      << ", form execution grade " << form.getExecutionGrade()
      << std::endl;

    return o;
}