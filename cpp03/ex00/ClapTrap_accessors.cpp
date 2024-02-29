#include "ClapTrap.hpp"

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

int ClapTrap::getHitPoints() const { return _hit_pts; }

int ClapTrap::getAttack() const { return _attack_dmg; }

int ClapTrap::getEnergy() const { return _energy_pts; }

void ClapTrap::setColor(string color) { _COLOR = color; }

string ClapTrap::getColor() const { return _COLOR; }

void ClapTrap::setModel(string model) { _model = model; }

string ClapTrap::getModel() const { return _model; }

const string &ClapTrap::getName() const { return _name; }

string ClapTrap::getFullName() const
{
	std::stringstream sstr;
	sstr << _COLOR << _model << " " << _name << "\033[37m";
	return sstr.str();
}