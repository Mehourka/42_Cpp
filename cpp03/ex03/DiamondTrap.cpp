#include "DiamondTrap.hpp"

void DiamondTrap::_init()
{
	setModel("DiamondTrap");
	setColor("\033[34m");
	setHitPoints(FragTrap::_hit_pts);
	setEnergy(ScavTrap::_energy_pts);
	setAttack(FragTrap::_attack_dmg);
}

DiamondTrap::DiamondTrap(): ClapTrap()
{
	_init();
	_log(("DiamondTrap Default constructor called"));
}

DiamondTrap::~DiamondTrap()
{
	_log("DiamondTrap Destructor called");
}

DiamondTrap::DiamondTrap(DiamondTrap &other): ClapTrap(other)
{
	_log(("DiamondTrap Copy constructor called"));
}

DiamondTrap::DiamondTrap(string name)
: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_init();
	ClapTrap::_name = name + "_clap_name";
	_name = name;
	_log(("DiamondTrap String constructor called"));
}

void DiamondTrap::whoAmI()
{
	std::stringstream sstr;
	sstr << "Who you ask ? many know me as " << getFullName()
		<< ".\n\tBut deep down, I'll always be " << ClapTrap::getFullName();
	_info(sstr.str());
}

void DiamondTrap::attack(const std::string &target_name)
{
	ScavTrap::attack(target_name);
}

const string &DiamondTrap::getName() const { return _name; }

string DiamondTrap::getFullName() const
{
	std::stringstream sstr;
	sstr << _COLOR << _model << " " << _name << "\033[37m";
	return sstr.str();
}

void DiamondTrap::setColor(string color) { _COLOR = color; }

string DiamondTrap::getColor() const { return _COLOR; }

void DiamondTrap::setModel(string model) { _model = model; }

string DiamondTrap::getModel() const { return _model; }

