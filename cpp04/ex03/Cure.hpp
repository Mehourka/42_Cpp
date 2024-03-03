#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();						   // Canonical
	~Cure();					   // Canonical
	Cure(const Cure &);			   // Canonical
	Cure &operator=(const Cure &); // Canonical

public:
	Cure* clone() const;
	void use(ICharacter& target);
};