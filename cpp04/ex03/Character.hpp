#pragma once
#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	ICharacter();							   // Canonical
	ICharacter(const ICharacter &);			   // Canonical
	ICharacter &operator=(const ICharacter &); // Canonical
	~ICharacter();							   // Cannonical - Interface

	std::string const &getName() const = 0;	   // Interface
	void equip(AMateria *m) = 0;			   // Interface
	void unequip(int idx) = 0;				   // Interface
	void use(int idx, ICharacter &target) = 0; // Interface
};
