#pragma once
#include "Common.hpp"

class Form
{
private:
    const string _name;
    const int _executionGrade;
    const int _signatureGrade;
    bool _isSigned;
    static const int MaxGrade = 150;
    static const int MinGrade = 1;

private:
    Form(); // Canonical
public:
    Form(const string &, const int &, const int &);
    Form(const Form &);            // Canonical
    Form &operator=(const Form &); // Canonical
    ~Form();                       // Canonical

private:
    void validateGrade(const int &);

public:
    string getName() const;
    int getSignatureGrade() const;
    int getExecutionGrade() const;
    bool getIsSigned() const;

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

std::ostream &operator<<(std::ostream &o, const Form &f);