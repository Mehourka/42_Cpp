#pragma once
#include "Animal.hpp"

class Cat: public Animal
{
protected:
    std::string _type;

public:
    Cat();                              //Canonical
    ~Cat();                             //Canonical
    Cat(const Cat &);                   //Canonical
    Cat & operator = (const Cat &);     //Canonical

    void makeSound();
};

// std::ostream &operator<<(std::ostream &, Cat &);
