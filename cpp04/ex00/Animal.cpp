#include "Animal.hpp"

Animal::Animal()
{
   std::cout << GRAY << "Animal Default Constructor called" << std::endl;
}

Animal::~Animal()
{
   std::cout << GRAY << "Animal Default Destructor called" << std::endl;
}

Animal::Animal(const Animal &other)
{
    *this = other;
    std::cout << GRAY << "Animal Copy Constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << GRAY << "Animal Assignation Constructor called" << std::endl;
    _type = other.getType();
    return *this;
}

// Animal::Animal(string name)
// {
// }

void Animal::makeSound()
{
    std::cout << "* Animal sound *" << std::endl;
}

std::string Animal::getType() const{
    return _type;
}

std::ostream &operator<<(std::ostream &o, Animal & animal)
{
    std::cout << GRAY << animal.getType() << WHITE << std::endl;
	return o;
}
