#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    // string _name;
    string _COLOR;
    string _model;

protected:
    ScavTrap();                             // Canonical
public:
    virtual ~ScavTrap();                    // Canonical
    ScavTrap(ScavTrap &);                   // Canonical
    ScavTrap &operator=(const ScavTrap &);  // Canonical

    ScavTrap(string name);
    void _init();

    void attack(const std::string &target);
    void guardGate();

protected:
    virtual void setModel(string);
    virtual string getModel() const;
    virtual string getColor() const;
    virtual string getFullName() const;

public:
    virtual void setColor(string color);
    virtual const string &getName() const;
};
