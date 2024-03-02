#include "AMateria.hpp"

AMateria::AMateria()
{
	Log("AMateria Default Constr. called");
	pushMateria();
}

AMateria::AMateria(const std::string &type) : _type(type)
{
	Log("AMateria String Constr. called");
	pushMateria();
}

AMateria::AMateria(const AMateria &other)
{
	Log("AMateria Copy Constr. called");
	pushMateria();
	*this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	Log("AMateria Assign. Override called");
	this->_type = other.getType();

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