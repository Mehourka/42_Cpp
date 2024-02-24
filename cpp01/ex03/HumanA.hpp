#pragma once
#include "Human.hpp"

class HumanA : public Human
{
private:
	Weapon &_weapon;

public:
	HumanA(string, Weapon&);

	const string getWeaponType();
};
