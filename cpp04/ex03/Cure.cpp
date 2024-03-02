#include "Cure.hpp"

Cure::Cure() : AMateria("Cure")
{
	Log("Cure Def. Constr. called\n");

}
Cure::~Cure()
{
	Log("Cure Dest. called");

}
Cure::Cure(const Cure &other) : AMateria(other)
{
	Log("Cure Copy Constr. called");
	*this = other;
}
Cure &Cure::operator=(const Cure &)
{
	Log("Cure Assign. Override called");
	// Deep copy here
	return *this;
}

Cure *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}