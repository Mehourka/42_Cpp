#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();                            // Canonical
    ~WrongCat();                           // Canonical
    WrongCat(const WrongCat &);            // Canonical
    WrongCat &operator=(const WrongCat &); // Canonical

    void makeSound() const;
};
