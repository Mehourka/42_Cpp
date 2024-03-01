#pragma once
#include "Animal.hpp"

class Cat: public Animal
{
public:
    Cat();                              //Canonical
    ~Cat();                             //Canonical
    Cat(const Cat &);                   //Canonical
    Cat & operator = (const Cat &);     //Canonical

    void makeSound() const;
};

// std::ostream &operator<<(std::ostream &, Cat &);
