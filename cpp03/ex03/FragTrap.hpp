#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    // string _name;
    int _hit_pts;
    int _energy_pts;
    int _attack_dmg;
    string _model;
    string _COLOR;

protected:
    FragTrap();                             // Canonical
public:
    virtual ~FragTrap();                    // Canonical
    FragTrap(FragTrap &);                   // Canonical
    FragTrap &operator=(const FragTrap &);  // Canonical

    FragTrap(string name);
    void _init();

    void highFivesGuys(void);

protected:
    virtual void setModel(string);
    virtual string getModel() const;
    virtual string getColor() const;
    virtual string getFullName() const;

public:
    virtual void setColor(string);
    virtual const string &getName() const;
};
