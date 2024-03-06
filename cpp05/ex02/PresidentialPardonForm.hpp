#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    PresidentialPardonForm();                                          // Canonical
    PresidentialPardonForm &operator=(const PresidentialPardonForm &); // Canonical
public:
    PresidentialPardonForm(const string &target);
    PresidentialPardonForm(const PresidentialPardonForm &); // Canonical
    ~PresidentialPardonForm();                              // Canonical

public:
    void formAction() const;
};
