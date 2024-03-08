#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    RobotomyRequestForm();                                          // Canonical
    RobotomyRequestForm &operator=(const RobotomyRequestForm &); // Canonical
public:
    RobotomyRequestForm(const string &target);
    RobotomyRequestForm(const RobotomyRequestForm &); // Canonical
    ~RobotomyRequestForm();                              // Canonical

public:
    void formAction() const;
};
