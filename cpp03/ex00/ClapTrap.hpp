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
    static clap_list_t *targets;
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
private:
    void popTarget(string name);
    void pushTarget();
    ClapTrap *findTarget(string name);

private:
    unsigned int _ensurePositive(int);
    ClapTrap *getTarget(const string &);
    bool canAct(ClapTrap * Target, string previx);

protected:
    void _log(const string str) const;
    void _info(const string str) const;
    void setHitPoints(int val);
    void setEnergy(int val);
    int getHitPoints() const;
    int getAttack() const;
    int getEnergy() const;
    string getFullName() const;
    string getColor() const;
    void setModel(string);
    string getModel() const;


private:
    string getUniqueName(const string) const;


public:
    void setAttack(int val);
    static void printTargets();
    const string &getName() const;
    void setColor(string);
    friend std::ostream& operator<<(std::ostream&, ClapTrap &);
};

// std::ostream &operator<<(std::ostream &, ClapTrap &);
