#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
protected:
    string _name;
    string _model;
    string _COLOR;

protected:
    DiamondTrap();                          // Canonical

public:
    virtual ~DiamondTrap();                 // Canonical
    DiamondTrap(DiamondTrap &);             // Canonical
    DiamondTrap &operator=(DiamondTrap &);  // Canonical

    DiamondTrap(string name);
    void _init();

    void whoAmI();

protected:
    string getFullName() const;
    virtual void setModel(string);
    virtual string getModel() const;
    virtual string getColor() const;


public:
    virtual void setColor(string);
    const string &getName() const;
    void attack(const std::string &target);

};
