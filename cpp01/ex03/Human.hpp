#pragma once
#include "Weapon.hpp"
#include <iostream>

class Human
{
private:
    string _name;
	Human();

public:
	Human(string);
	~Human();

    void attack();
	string getName();
	virtual const string getWeaponType();
};
