#include "Dog.hpp"

Dog::Dog(): _type("Dog")
{
    Log("Dog Default Constructor called");
}

Dog::~Dog()
{
    Log("Dog Default Destructor called");
    
}

Dog::Dog(const Dog &other)
{
    *this = other;
    Log("Dog Copy Constructor called");

}

Dog &Dog::operator=(const Dog &other)
{
    Log("Dog Assignaion Constructor called");

    _type = other.getType();
    return *this;
}

std::string Dog::getType() const{
    return _type;
}


void Dog::makeSound() const
{
    std::cout << "* Dog sound *" << std::endl;
}

