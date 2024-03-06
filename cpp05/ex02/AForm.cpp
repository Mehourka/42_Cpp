#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Blank Paper"),
      _signatureGrade(150),
      _executionGrade(150),
      _isSigned(false)
{
    Log("[ AForm ] Default Constructor");
}

AForm::AForm(const string &name, const int &signatureGrade, const int &executionGrade)
    : _name(name),
      _signatureGrade(signatureGrade),
      _executionGrade(executionGrade),
      _isSigned(false)
{
    Log("[ AForm ] Name/Grade Constructor");
    validateGrade(_executionGrade);
    validateGrade(_signatureGrade);
}

AForm::AForm(const AForm &other)
    : _name(other.getName()),
      _signatureGrade(other.getSignatureGrade()),
      _executionGrade(other.getExecutionGrade()),
      _isSigned(false)
{
    Log("[ AForm ] Copy Constructor");
    validateGrade(_signatureGrade);
    validateGrade(_executionGrade);
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

void AForm::setTarget(const string &target)
{
    _target = target;
}

std::string AForm::getTarget() const
{
    return _target;
}

void AForm::beSigned(const Bureaucrat &b)
{
    if (b.getGrade() > getSignatureGrade())
    {
        throw AForm::GradeTooLowException();
    }
    _isSigned = true;
}

void AForm::execute(const Bureaucrat & exec) const
{
    if (exec.getGrade() > getExecutionGrade())
        throw AForm::GradeTooLowException();
    if (_isSigned == false)
        throw AForm::UnsignedFormException();

    formAction();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("[ GradeTooHighException] Grade is higher than max: 1");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("[ GradeTooLowException] Grade is lower than expected");
}

const char *AForm::UnsignedFormException::what() const throw()
{
    return ("[ UnsignedFormException ] Cannot execute unsigned form");
}

std::ostream &operator<<(std::ostream &o, const AForm &form)
{
    o << BLUE << form.getName()
      << ", signature grade " << form.getSignatureGrade()
      << ", execution grade " << form.getExecutionGrade()
      << WHITE;
    return o;
}