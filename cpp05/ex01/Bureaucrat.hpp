#pragma once
#include "Common.hpp"

class Bureaucrat
{
private:
    const string _name;
    int _grade;
    static const int MaxGrade = 150;
    static const int MinGrade = 1;

private:
    Bureaucrat(); // Canonical
public:
    Bureaucrat(const string &name, const int &grade);
    Bureaucrat(const Bureaucrat &);            // Canonical
    Bureaucrat &operator=(const Bureaucrat &); // Canonical
    ~Bureaucrat();                             // Canonical

private:
    void setGrade(const int &);

public:
    string getName() const;
    int getGrade() const;
    void upgrade();
    void downgrade();

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

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);