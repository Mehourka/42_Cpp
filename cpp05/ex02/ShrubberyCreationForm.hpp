#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    ShrubberyCreationForm();                                         // Canonical
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &); // Canonical
public:
    ShrubberyCreationForm(const string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &); // Canonical
    ~ShrubberyCreationForm();                             // Canonical

public:
    void formAction() const;
};
