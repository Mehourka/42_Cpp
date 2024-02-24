#pragma once
#include "Weapon.hpp"
#include <iostream>

class Human
{
private:
    string name;

public:
	Human();
	Human(string);
	~Human();

    void attack();
	virtual const string getWeaponType();
	string getName();
};