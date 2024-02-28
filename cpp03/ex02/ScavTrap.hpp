#pragma once

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
protected:
    ScavTrap();
public:
    virtual ~ScavTrap();
    ScavTrap(ScavTrap &);
    ScavTrap & operator = (ScavTrap &);

    ScavTrap(string name);
    void _init();

    void guardGate();
};
