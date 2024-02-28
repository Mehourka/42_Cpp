#include "FragTrap.hpp"

void FragTrap::_init()
{
	setModel("FragTrap");
	setColor("\033[31m");
	setHitPoints(100);
	setEnergy(100);
	setAttack(30);
}

FragTrap::FragTrap(): ClapTrap()
{
	_init();
	_log(("FragTrap Default constructor called"));
}

FragTrap::~FragTrap()
{
	_log("FragTrap Destructor called");
}

FragTrap::FragTrap(FragTrap &other): ClapTrap(other)
{
	_log(("FragTrap Copy constructor called"));
}

FragTrap::FragTrap(string name): ClapTrap(name)
{
	_init();
	_log(("FragTrap String constructor called"));
}

void FragTrap::highFivesGuys(void)
{
	std::stringstream sstr;
	sstr << getFullName() << " wants a HighFive 🖐️";

	_log(sstr.str());
}
