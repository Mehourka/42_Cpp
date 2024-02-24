#include "Weapon.hpp"
#include "Human.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>



int main(void)
{


	Weapon sword = Weapon("Short sword");
	Weapon club = Weapon("Wooden club");


	// This should not work
	// HumanA anon = HumanA("Anon");

	HumanA andy = HumanA("Andy", sword);
	HumanA alex = HumanA("Alex", sword);
	andy.attack();
	sword.setType("Long sword");
	alex.attack();

	std::cout << "\n";

	// HumanB can pickup weapons
	HumanB bob = HumanB("Bob", club);
	HumanB bill = HumanB("Bill");
	HumanB brutus = HumanB("Brutus");
	bob.attack();
	club.setType("Great Club +3");
	bill.setWeapon(club);
	bill.attack();
	brutus.attack();









}

