#include "Dog.hpp"

Dog::Dog()
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

// Dog::Dog(string name)
// {
// }

void Dog::makeSound()
{
    std::cout << "* Dog sound *" << std::endl;
}

// std::ostream &operator<<(std::ostream &o, Dog &other)
// {
// 	return o;
// }
