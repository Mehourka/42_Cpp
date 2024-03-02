#include "Cure.hpp"

Cure::Cure()
{

}
Cure::~Cure()
{

}
Cure::Cure(const Cure & other)
{
	*this = other;
}
Cure & Cure::operator = (const Cure &)
{
	// Deep copy here
	return *this;
}

Cure * Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;

}