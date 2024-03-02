#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();						 // Canonical
	~Ice();						 // Canonical
	Ice(const Ice &);			 // Canonical
	Ice &operator=(const Ice &); // Canonical

public:
	Ice *clone() const;
	void use(ICharacter& target);
};

typedef Ice ice;