#pragma once
#include "Animal.hpp"

class Dog: public Animal
{
protected:
    std::string _type;

public:
    Dog();                          //Canonical
    ~Dog();                         //Canonical
    Dog(const Dog &);               //Canonical
    Dog & operator = (const Dog &); //Canonical

    void makeSound();
};

// std::ostream &operator<<(std::ostream &, Dog &);
