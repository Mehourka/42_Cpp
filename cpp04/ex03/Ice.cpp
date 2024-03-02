#include "Ice.hpp"

Ice::Ice() : AMateria("Ice")
{
	Log("Ice Default Constr. called\n");
}

Ice::~Ice()
{
	Log("Ice Dest. called");
}
Ice::Ice(const Ice &other): AMateria(other)
{
	Log("Ice Copy Constr. called\n");
	*this = other;
}
Ice &Ice::operator=(const Ice &)
{
	Log("Ice Assign. Override called\n");
	// Deep copy here
	return *this;
}

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}