#pragma once
#include "Human.hpp"

class HumanA : public Human
{
private:
	Weapon &weapon;

public:
	HumanA(string, Weapon&);

	const string getWeaponType();
};