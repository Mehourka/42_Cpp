#pragma once
#include "Common.hpp"

class ClapTrap;

// Clap trap linked list for searching targets
typedef struct targets_s
{
    ClapTrap *clap;
    struct targets_s *next;
} clap_list_t;

class ClapTrap
{
protected:
    string _name;
    int _hit_pts;
    int _energy_pts;
    int _attack_dmg;
    static clap_list_t *targets;

protected:
    string _model;
    string _COLOR;

    // Constructors / Desctructor
protected:
    ClapTrap(); // Canonical
    void _init();

public:
    ClapTrap(string name);
    ClapTrap(const ClapTrap &);            // Canonical
    virtual ~ClapTrap();                   // Canonical
    ClapTrap &operator=(const ClapTrap &); // Canonical

    // Mandatory
public:
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    // Linked List methods
protected:
    void popTarget(string name);
    void pushTarget();
    ClapTrap *findTarget(string name);

protected:
    unsigned int _ensurePositive(int);
    ClapTrap *getTarget(const string &);
    bool canAct(ClapTrap *Target, string previx);

protected:
    void _log(const string str) const;
    void _info(const string str) const;
    virtual void setHitPoints(int val);
    virtual void setEnergy(int val);
    virtual int getHitPoints() const;
    virtual int getAttack() const;
    virtual int getEnergy() const;
    virtual string getColor() const;
    virtual void setModel(string);
    virtual string getModel() const;

protected:
    string getUniqueName(const string) const;

public:
    virtual string getFullName() const;
    virtual void setAttack(int val);
    static void printTargets();
    virtual const string &getName() const;
    virtual void setColor(string);
    friend std::ostream &operator<<(std::ostream &, ClapTrap &);
};

// std::ostream &operator<<(std::ostream &, ClapTrap &);
