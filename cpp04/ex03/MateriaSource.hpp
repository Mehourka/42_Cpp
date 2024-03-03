#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
public:
	static const int Capacity = 4;

private:
	AMateria *_slots[MateriaSource::Capacity];

public:
	MateriaSource(); // Canonical
	MateriaSource(const MateriaSource &);			  // Canonical
	MateriaSource &operator=(const MateriaSource &);  // Canonical
	~MateriaSource();								  // Interface
	void learnMateria(AMateria *);					  // Interface
	AMateria *createMateria(std::string const &type); // Interface

private:
	void deleteSrcSlots();
};
