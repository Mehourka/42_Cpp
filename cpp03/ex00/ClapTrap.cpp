#include "ClapTrap.hpp"

clap_list_t *ClapTrap::targets = NULL;

void ClapTrap::_init()
{
	setHitPoints(10);
	setEnergy(10);
	setAttack(0);
	pushTarget();
}
void ClapTrap::_log(const string str) const
{
	std::cout
		<< "\033[30m - [ " << _name << " ]  "
		<< (str) << "\033[37m" << std::endl;
}

void ClapTrap::_info(const string str) const
{
	std::cout
		<< "\033[30m - [ " << _name << " ]  "
		<< "\033[37m" << (str) << "\n" << std::endl;
}

ClapTrap::ClapTrap()
{
	_log(("Default constructor called : "));
	_name = "Anon";
	_init();
}

ClapTrap::ClapTrap(string name)
{
	_name = getUniqueName(name);
	_log("String constructor called");
	_init();
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	_log("Copy constructor called");
	*this = other;
}

ClapTrap::~ClapTrap()
{
	_log("Destructor called");
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

unsigned int ClapTrap::_ensurePositive(int val)
{
	return val < 0 ? 0 : val;
}

ClapTrap *ClapTrap::getTarget(const string &target)
{
	// Todo : Actually find the target...
	return findTarget(target);
}

// TODO: Cant attack if dead
// TODO: Add separate function that checks hp and energy, then logs

bool ClapTrap::canAct(ClapTrap * target, string prefix)
{
	std::stringstream sstr;

	sstr << prefix;
	if (!target)
	{
		sstr << ": Invalid Target";
	}
	else if (getHitPoints() == 0)
	{
		sstr << " " << target->getName()
			<< " : Has 0 Hit Points (dead)";
	}
	else if (getEnergy() == 0)
	{
		sstr << " " << target->getName()
			<< " : Has 0 Energy Points";
	}
	else
	{
		return true;
	}
	_info(sstr.str());
	return false;
}

void ClapTrap::attack(const std::string &target_name)
{
	ClapTrap *target = getTarget(target_name);
	if (!canAct(target, "Can't attack"))
		return;

	std::stringstream info;
	info << "ClapTrap " << _name
		 << " attacks " << target->getName()
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

void ClapTrap::setHitPoints(int val)
{
	_hit_pts = _ensurePositive(val);
}

void ClapTrap::setAttack(int val)
{
	_attack_dmg = _ensurePositive(val);
}

void ClapTrap::setEnergy(int val)
{
	_energy_pts = _ensurePositive(val);
}

int ClapTrap::getHitPoints() const
{
	return _hit_pts;
}

int ClapTrap::getAttack() const
{
	return _attack_dmg;
}

int ClapTrap::getEnergy() const
{
	return _energy_pts;
}

const string &ClapTrap::getName() const
{
	return _name;
}

std::ostream &operator<<(std::ostream &o, ClapTrap &clap)
{
	o << "\033[30m - [ " << clap.getName() << " ]\033[32m status: "
	  << " HP: " << clap.getHitPoints()
	  << " Enrg.: " << clap.getEnergy()
	  << " Attack: " << clap.getAttack() << std::endl;
	return o;
}
