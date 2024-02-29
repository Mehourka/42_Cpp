#include "FragTrap.hpp"

void FragTrap::_init()
{
	setModel("FragTrap");
	setColor("\033[31m");
	setHitPoints(100);
	_hit_pts = 100;
	setEnergy(100);
	_energy_pts = 100;
	setAttack(30);
	_attack_dmg = 30;
}

FragTrap::FragTrap() : ClapTrap()					// Canonical
{
	_init();
	_log(("FragTrap Default constructor called"));
}

FragTrap::~FragTrap()								// Canonical
{
	_log("FragTrap Destructor called");
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	_log(("FragTrap Copy constructor called"));
}

FragTrap::FragTrap(string name) : ClapTrap(name)
{
	_init();
	_log(("FragTrap String constructor called"));
}

void FragTrap::highFivesGuys(void)
{
	if (!canAct(this, "Can't HighFive"))
		return;
	std::stringstream sstr;
	sstr << getFullName() << " wants a HighFive 🖐️";
	_log(sstr.str());

	this->setEnergy(this->getEnergy() - 1);
}

void FragTrap::setColor(string color) { _COLOR = color; }

string FragTrap::getColor() const { return _COLOR; }

void FragTrap::setModel(string model) { _model = model; }

string FragTrap::getModel() const { return _model; }

const string &FragTrap::getName() const { return _name; }

string FragTrap::getFullName() const
{
	std::stringstream sstr;
	sstr << _COLOR << _model << " " << _name << "\033[37m";
	return sstr.str();
}