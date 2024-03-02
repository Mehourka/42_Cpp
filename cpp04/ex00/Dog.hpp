#pragma once
#include "Animal.hpp"

class Dog : public Animal
{

public:
    Dog();                       // Canonical
    ~Dog();                      // Canonical
    Dog(const Dog &);            // Canonical
    Dog &operator=(const Dog &); // Canonical

    void makeSound() const;
};
