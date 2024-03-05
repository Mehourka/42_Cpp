#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Blank Paper"),
      _executionGrade(150),
      _signatureGrade(150),
      _isSigned(false)
{
    Log("[ AForm ] Default Constructor");
}

AForm::AForm(const string &name, const int &executionGrade, const int &signatureGrade)
    : _name(name),
      _executionGrade(executionGrade),
      _signatureGrade(signatureGrade),
      _isSigned(false)
{
    Log("[ AForm ] Name/Grade Constructor");
    validateGrade(_executionGrade);
    validateGrade(_signatureGrade);
}

AForm::AForm(const AForm &other)
    : _name(other.getName()),
      _executionGrade(other.getExecutionGrade()),
      _signatureGrade(other.getSignatureGrade()),
      _isSigned(false)
{
    Log("[ AForm ] Copy Constructor");
    validateGrade(_executionGrade);
    validateGrade(_signatureGrade);
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    Log("[ AForm ] Assigment Operator");

    this->_isSigned = other._isSigned;
    // Grades an name are const
    return *this;
}

AForm::~AForm()
{
    Log("[ AForm ] Default Destructor");
}

void AForm::validateGrade(const int &val)
{
    if (val > AForm::MaxGrade)
        throw AForm::GradeTooHighException();
    if (val < AForm::MinGrade)
        throw AForm::GradeTooLowException();
}

string AForm::getName() const
{
    return (_name);
}

int AForm::getSignatureGrade() const
{
    return (_signatureGrade);
}

int AForm::getExecutionGrade() const
{
    return (_executionGrade);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > getSignatureGrade())
        throw AForm::GradeTooLowException();
    _isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException: Grade is higher than max: 1");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException: Grade is lower than expected");
}

std::ostream &operator<<(std::ostream &o, const AForm &form)
{
    o << form.getName()
      << ", AForm signature grade " << form.getSignatureGrade()
      << ", AForm execution grade " << form.getExecutionGrade()
      << std::endl;

    return o;
}