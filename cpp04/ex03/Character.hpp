#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	static const int _inventory_size = 4;
	std::string _name;
	AMateria *_inventory[Character::_inventory_size];

private:
	Character(); // Canonical
public:
	Character(const std::string &);
	Character(const Character &);			 // Canonical
	Character &operator=(const Character &); // Canonical
	~Character();							 // Cannonical - Interface

public:									   // Mandatory
	std::string const &getName() const;	   // Interface
	void equip(AMateria *m);			   // Interface
	void unequip(int idx);				   // Interface
	void use(int idx, ICharacter &target); // Interface

private:
	void deleteInventory();

public:
	void printInventory() const;
};

std::ostream &operator<<(std::ostream &, const Character &);