#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    Log("Dog Default Constructor called\n");
}

Dog::~Dog()
{
    Log("Dog Default Destructor called");
}

Dog::Dog(const Dog &other) : Animal(other)
{
    *this = other;
    Log("Dog Copy Constructor called\n");
}

Dog &Dog::operator=(const Dog &other)
{
    Log("Dog Assignaion Constructor called");

    _type = other.getType();
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "* Dog sound *" << std::endl;
}
