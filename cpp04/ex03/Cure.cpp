#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	Log("Cure Def. Constr. called");

}

Cure::Cure(const Cure &other) : AMateria(other)
{
	Log("Cure Copy Constr. called");
	*this = other;
}

Cure &Cure::operator=(const Cure &)
{
	Log("Cure Assign. Override called");
	return *this;
}

Cure::~Cure()
{
	Log("Cure Dest. called");

}

Cure *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
