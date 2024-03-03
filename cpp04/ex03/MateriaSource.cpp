#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	Log("MateriaSource Default Constructor called");
	for (int i = 0; i < MateriaSource::Capacity; i++)
		_slots[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	Log("MateriaSource Copy Constructor called");
	*this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	Log("MateriaSource Assign. Constructor called");
	AMateria *otherSlot;

	deleteSrcSlots();
	for (int i = 0; i < MateriaSource::Capacity; i++)
	{
		otherSlot = other._slots[i];
		if (otherSlot)
			_slots[i] = otherSlot->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	deleteSrcSlots();
	Log("MateriaSource Default Destructor called");
}

void MateriaSource::deleteSrcSlots()
{
	AMateria *m;
	for (int i = 0; i < MateriaSource::Capacity; i++)
	{
		m = _slots[i];
		if (m)
			delete m;
		_slots[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < MateriaSource::Capacity; i++)
	{
		if (_slots[i] == NULL)
		{
			_slots[i] = m;
			return;
		}
	}
	std::cout << "Materia source full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *m;

	for (int i = 0; i < MateriaSource::Capacity; i++)
	{
		m = _slots[i];
		if (m && m->getType() == type)
		{
			return m->clone();
		}
	}
	return NULL;
}
