#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    Log("Animal Default Constructor called\n");
}

Animal::Animal(const string &type) : _type(type)
{
    Log("Animal String Constructor called");
}

Animal::Animal(const Animal &other)
{
    *this = other;
    Log("Animal Copy Constructor called");
}

Animal &Animal::operator=(const Animal &other)
{
    Log("Animal Assignation Constructor called");
    _type = other.getType();
    return *this;
}

Animal::~Animal()
{
    Log("Animal Default Destructor called\n");
}

void Animal::makeSound() const
{
    LogInfo("* Animal sound *");
}

std::string Animal::getType() const
{
    return _type;
}

std::ostream &operator<<(std::ostream &o, const Animal &animal)
{
    o << animal.getType() << std::endl;
    return o;
}
