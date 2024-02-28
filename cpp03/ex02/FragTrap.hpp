#pragma once

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
protected:
    FragTrap();
public:
    virtual ~FragTrap();
    FragTrap(FragTrap &);
    FragTrap & operator = (FragTrap &);

    FragTrap(string name);
    void _init();

    void highFivesGuys(void);
};
