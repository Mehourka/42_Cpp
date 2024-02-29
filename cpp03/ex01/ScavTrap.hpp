#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    // string _name;
    int _hit_pts;
    int _energy_pts;
    int _attack_dmg;
    string _COLOR;
    string _model;

protected:
    ScavTrap();

public:
    virtual ~ScavTrap();
    ScavTrap(ScavTrap &);
    ScavTrap &operator=(ScavTrap &);

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
