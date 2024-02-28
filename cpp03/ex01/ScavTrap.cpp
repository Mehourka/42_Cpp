#include "ScavTrap.hpp"

void ScavTrap::_init()
{
	setModel("ScavTrap");
	setColor("\033[35m");
	setHitPoints(100);
	setEnergy(50);
	setAttack(20);
}

ScavTrap::ScavTrap(): ClapTrap()
{
	_init();
	_log(("ScavTrap Default constructor called"));
}

ScavTrap::~ScavTrap()
{
	_log("ScavTrap Destructor called");
}

ScavTrap::ScavTrap(ScavTrap &other): ClapTrap(other)
{
	_log(("ScavTrap Copy constructor called"));
}

ScavTrap::ScavTrap(string name): ClapTrap(name)
{
	_init();
	_log(("ScavTrap String constructor called"));
}

void ScavTrap::guardGate()
{
	std::stringstream sstr;
	sstr << getFullName() << " est entré en mode Gate Keeper";

	_log(sstr.str());
}
