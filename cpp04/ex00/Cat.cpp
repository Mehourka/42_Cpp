#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    Log("Cat Default Constructor called");
}

Cat::~Cat()
{
    Log("Cat Default Destructor called");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    Log("Cat Copy Constructor called");
}

Cat &Cat::operator=(const Cat &other)
{
    Log("Cat Assignation Constructor called");
    _type = other.getType();
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "* Cat sound *" << std::endl;
}
