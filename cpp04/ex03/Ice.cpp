#include "Ice.hpp"

Ice::Ice()
{

}
Ice::~Ice()
{

}
Ice::Ice(const Ice & other)
{
	*this = other;
}
Ice & Ice::operator = (const Ice &)
{
	// Deep copy here
	return *this;
}

Ice * Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;

}