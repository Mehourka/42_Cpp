#pragma once

#include "Human.hpp"

class HumanB : public Human
{
private:
	Weapon *weapon;

public:
	HumanB(string);
	HumanB(string, Weapon&);

	void setWeapon(Weapon&);
	const string getWeaponType();
};