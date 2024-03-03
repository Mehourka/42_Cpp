#pragma once

#include "Common.hpp"
#include "ICharacter.hpp"

typedef struct m_list_s {
	AMateria		*materiaPTR;
	struct m_list_s	*next;
} m_list_t;

class AMateria
{
protected:
	std::string		_type;
	ICharacter		*_owner;
	static m_list_t	*materiaList;


protected:
	void pushMateria();
	void popMateria(AMateria *);

public:
	AMateria(std::string const &type);

	virtual ~AMateria();						// Canonical
	AMateria();									// Canonical
	AMateria(const AMateria &other);			// Canonical
	AMateria &operator=(const AMateria &other); // Canonical

	// ...
	std::string const &getType() const; // Returns the materia type

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter& target);
	ICharacter * getOwner() const;
	void setOwner(ICharacter *);

	AMateria & getItem(int idx);

	static void deleteUnequipedMaterias();
	static void printMateriaList();
};

std::ostream & operator << (std::ostream & o, const AMateria &);
