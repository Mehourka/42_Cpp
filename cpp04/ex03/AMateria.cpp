#include "AMateria.hpp"

AMateria::AMateria()
{
	Log("AMateria Default Constr. called");
	pushMateria();
}

AMateria::AMateria(const std::string &type) : _type(type), _owner(NULL)
{
	Log("AMateria String Constr. called");
	pushMateria();
}

AMateria::AMateria(const AMateria &other)
{
	Log("AMateria Copy Constr. called");
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	Log("AMateria Assign. Override called");
	this->_type = other.getType();
	this->_owner = NULL;
	pushMateria();
	return *this;
}

AMateria::~AMateria()
{
	Log("AMateria Dest. called\n");
	popMateria(this);
}

std::string const &AMateria::getType() const
{
	return _type;
}

ICharacter * AMateria::getOwner() const
{
	return _owner;
}

void AMateria::setOwner(ICharacter *newOwner)
{
	_owner = newOwner;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* Materia used on "
			  << target.getName() << " *" << std::endl;
}



std::ostream &operator<<(std::ostream &o, const AMateria &materia)
{
	o << materia.getType() << std::endl;
	return o;
}