#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("WrongAnimal")
{
   std::cout << GRAY << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const string &type): _type(type)
{
    Log("WrongAnimal String Constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    *this = other;
    std::cout << GRAY << "WrongAnimal Copy Constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << GRAY << "WrongAnimal Assignation Constructor called" << std::endl;
    _type = other.getType();
    return *this;
}

WrongAnimal::~WrongAnimal()
{
   std::cout << GRAY << "WrongAnimal Default Destructor called" << std::endl;
}



void WrongAnimal::makeSound() const
{
    std::cout << "* WrongAnimal sound *" << std::endl;
}

std::string WrongAnimal::getType() const{
    return _type;
}

std::ostream &operator<<(std::ostream &o, WrongAnimal & WrongAnimal)
{
    std::cout << WrongAnimal.getType() << std::endl;
	return o;
}
