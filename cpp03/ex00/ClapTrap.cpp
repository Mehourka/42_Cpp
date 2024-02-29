#include "ClapTrap.hpp"

clap_list_t *ClapTrap::targets = NULL;

void ClapTrap::_init()
{
	setColor("\033[33m");
	setModel("ClapTrap");
	setHitPoints(10);
	// _hit_pts = 10;
	setEnergy(10);
	// _energy_pts = 10;
	setAttack(0);
	// _attack_dmg = 0;
	pushTarget();
}

// -------------------- Canonical methods -------------------- //
ClapTrap::ClapTrap()
{
	_name = "Anon";
	_init();
	_log(("ClapTrap Default constructor called : "));
}

ClapTrap::ClapTrap(string name)
{
	_name = getUniqueName(name);
	_init();
	_log("ClapTrap String constructor called");
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	_log("ClapTrap Copy constructor called");
	*this = other;
}

ClapTrap::~ClapTrap()
{
	_log("ClapTrap Destructor called");
	popTarget(getName());
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	_name = other._name;
	setAttack(other.getAttack());
	setEnergy(other.getEnergy());
	setHitPoints(other.getHitPoints());
	return *this;
}

// -------------------- Mandatory Public Actions -------------------- //

void ClapTrap::attack(const std::string &target_name)
{
	ClapTrap *target = getTarget(target_name);
	if (!canAct(target, "Can't attack"))
		return;

	std::stringstream info;
	info << getFullName()
		 << " attacks " << target->getFullName()
		 << " causing " << this->getAttack() << " points of damage!";
	_info(info.str());

	target->takeDamage(getAttack());
	this->setEnergy(this->getEnergy() - 1);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoints() == 0)
	{
		_info("Can't take more damage: Is already dead");
		return;
	}
	this->setHitPoints(this->getHitPoints() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canAct(this, "Can't repaire"))
		return;
	std::stringstream info;
	info << "Repaired himself, gaining +"
		 << amount << " Hit Points";
	_info(info.str());

	this->setEnergy(this->getEnergy() - 1);
	this->setHitPoints(this->getHitPoints() + amount);
}

// -------------------- Utils -------------------- //

unsigned int ClapTrap::_ensurePositive(int val)
{
	return val < 0 ? 0 : val;
}

ClapTrap *ClapTrap::getTarget(const string &target)
{
	return findTarget(target);
}

bool ClapTrap::canAct(ClapTrap *target, string prefix)
{
	std::stringstream sstr;

	sstr << prefix;
	if (!target)
	{
		sstr << ": Invalid Target";
	}
	else if (getHitPoints() == 0)
	{
		sstr << " " << target->getFullName()
			 << " : Has 0 Hit Points (dead)";
	}
	else if (getEnergy() == 0)
	{
		sstr << " " << target->getFullName()
			 << " : Has 0 Energy Points";
	}
	else
	{
		return true;
	}
	_info(sstr.str());
	return false;
}

// -------------------- Printing / Log -------------------- //
std::ostream &operator<<(std::ostream &o, ClapTrap &clap)
{
	o << clap.getColor() << " - [ " << clap.getName() << " ] status: "
	  << " HP: " << clap.getHitPoints()
	  << " Enrg.: " << clap.getEnergy()
	  << " Attack: " << clap.getAttack() << std::endl;
	return o;
}

void ClapTrap::_log(const string str) const
{
	std::cout
		<< getColor() << " - [ " << getName() << " ] \033[30m"
		<< (str) << "\033[37m" << std::endl;
}

void ClapTrap::_info(const string str) const
{
	std::cout
		<< getColor() << " - [ " << getName() << " ] "
		<< "\033[37m" << (str) << "\n"
		<< std::endl;
}
