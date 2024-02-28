#include "Common.hpp"

class ClapTrap
{
private:
    string  _name;
    int     _hit_pts;
    int     _energy_pts;
    int     _attack_dmg;

public:
    static ClapTrap dummy;

private:
    ClapTrap(); // Canonical
    void _init();
    unsigned int _ensurePositive(int);
    ClapTrap * getTarget(const string &);
    void _log(const string str) const;
    void _info(const string str) const;

public:
    ClapTrap(string name);
    ClapTrap(const ClapTrap&);  // Canonical
    virtual ~ClapTrap();    // Canonical
    ClapTrap & operator = (const ClapTrap &);   // Canonical

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    void setHitPoints(int val);
    void setAttack(int val);
    void setEnergy(int val);
    int getHitPoints() const;
    int getAttack() const;
    int getEnergy() const;
    const string & getName() const;
};

std::ostream & operator << (std::ostream &, ClapTrap &);