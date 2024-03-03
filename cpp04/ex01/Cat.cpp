#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain())
{
    Log("Cat Default Constructor called\n");
}

Cat::~Cat()
{
    delete this->_brain;
    Log("Cat Default Destructor called");
}

Cat::Cat(const Cat &other) : Animal(other)
{
    *this = other;
    Log("Cat Copy Constructor called\n");
}

Cat &Cat::operator=(const Cat &other)
{
    Log("Cat Assignation Constructor called");
    _type = other.getType();
    delete this->_brain;
    this->_brain = new Brain(*other._brain);
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "* Cat sound *" << std::endl;
}

void Cat::addIdea(int idx, const std::string &idea)
{
    this->_brain->addIdea(idx, idea);
}

void Cat::printIdeas() const
{
    this->_brain->printIdeas();
}
