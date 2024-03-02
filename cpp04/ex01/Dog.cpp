#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain())
{
    Log("Dog Default Constructor called\n");
}

Dog::~Dog()
{
    delete this->_brain;
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
    this->_brain = new Brain(*other._brain);
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "* Dog sound *" << std::endl;
}

void Dog::addIdea(int idx, const std::string &idea)
{
    this->_brain->addIdea(idx, idea);
}

void Dog::printIdeas() const
{
    this->_brain->printIdeas();
}