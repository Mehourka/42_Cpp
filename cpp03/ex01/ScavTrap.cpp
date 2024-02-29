#include "ScavTrap.hpp"

void ScavTrap::_init()
{
	setModel("ScavTrap");
	setColor("\033[35m");
	setHitPoints(100);
	_hit_pts = 100;
	setEnergy(50);
	_energy_pts = 50;
	setAttack(20);
	_attack_dmg = 20;
}

ScavTrap::ScavTrap() : ClapTrap()
{
	_init();
	_log(("ScavTrap Default constructor called"));
}

ScavTrap::~ScavTrap()
{
	_log("ScavTrap Destructor called");
}

ScavTrap::ScavTrap(ScavTrap &other) : ClapTrap(other)
{
	_log(("ScavTrap Copy constructor called"));
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
	_init();
	_log(("ScavTrap String constructor called"));
}

void ScavTrap::attack(const std::string &target_name)
{
	ClapTrap *target = getTarget(target_name);
	if (!canAct(target, "Can't attack"))
		return;

	std::stringstream info;
	info << getFullName()
		 << " SCAV's the hell out of " << target->getFullName()
		 << " causing " << this->getAttack() << " points of damage!";
	_info(info.str());

	target->takeDamage(getAttack());
	this->setEnergy(this->getEnergy() - 1);
}

void ScavTrap::guardGate()
{
	std::stringstream sstr;
	sstr << getFullName() << " est entré en mode Gate Keeper";

	_log(sstr.str());
}

void ScavTrap::setColor(string color) { _COLOR = color; }

string ScavTrap::getColor() const { return _COLOR; }

void ScavTrap::setModel(string model) { _model = model; }

string ScavTrap::getModel() const { return _model; }

const string &ScavTrap::getName() const { return _name; }

string ScavTrap::getFullName() const
{
	std::stringstream sstr;
	sstr << _COLOR << _model << " " << _name << "\033[37m";
	return sstr.str();
}