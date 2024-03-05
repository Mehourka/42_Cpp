#pragma once
#include "Common.hpp"

class Bureaucrat;

class AForm
{
private:
    const string _name;
    const int _executionGrade;
    const int _signatureGrade;
    bool _isSigned;
    static const int MaxGrade = 150;
    static const int MinGrade = 1;

private:
    AForm(); // Canonical
public:
    AForm(const string &, const int &, const int &);
    AForm(const AForm &);            // Canonical
    AForm &operator=(const AForm &); // Canonical
    virtual ~AForm() = 0;                       // Canonical

private:
    void validateGrade(const int &);

public:
    string getName() const;
    int getSignatureGrade() const;
    int getExecutionGrade() const;
    bool getIsSigned() const;
    void beSigned(const Bureaucrat &);

    // Exception classes
public:
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const AForm &f);
