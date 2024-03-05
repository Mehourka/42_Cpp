#pragma once
#include "Common.hpp"

class Bureaucrat
{
private:
    int _attr;

public:
    Bureaucrat();                              // Canonical
    Bureaucrat(const Bureaucrat &);            // Canonical
    Bureaucrat &operator=(const Bureaucrat &); // Canonical
    ~Bureaucrat();                             // Canonical

    void sayHello() const;
};
