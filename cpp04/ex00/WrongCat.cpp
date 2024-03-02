#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    _type = "WrongCat";
    Log("WrongCat Default Constructor called");
}

WrongCat::~WrongCat()
{
    Log("WrongCat Default Destructor called");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    *this = other;
    Log("WrongCat Copy Constructor called");
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    Log("WrongCat Assignation Constructor called");
    _type = other.getType();
    return *this;
}

void WrongCat::makeSound() const
{
    std::cout << "* WrongCat sound *" << std::endl;
}
