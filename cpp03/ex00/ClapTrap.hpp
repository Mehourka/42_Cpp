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
private:
    string _name;
    int _hit_pts;
    int _energy_pts;
    int _attack_dmg;

private:
    static clap_list_t *targets;

    void popTarget(string name);
    void pushTarget();
    ClapTrap *findTarget(string name);

public:
    static void printTargets();

private:
    ClapTrap(); // Canonical
    void _init();
    unsigned int _ensurePositive(int);
    ClapTrap *getTarget(const string &);
    void _log(const string str) const;
    void _info(const string str) const;

public:
    ClapTrap(string name);
    ClapTrap(const ClapTrap &);            // Canonical
    virtual ~ClapTrap();                   // Canonical
    ClapTrap &operator=(const ClapTrap &); // Canonical

    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

    bool canAct(ClapTrap * Target, string previx);

    void setHitPoints(int val);
    void setAttack(int val);
    void setEnergy(int val);
    int getHitPoints() const;
    int getAttack() const;
    int getEnergy() const;
    const string &getName() const;
    string getUniqueName(const string) const;
};

std::ostream &operator<<(std::ostream &, ClapTrap &);
