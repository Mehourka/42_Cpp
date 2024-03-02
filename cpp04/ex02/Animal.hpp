#pragma once
#include "Common.hpp"

class Animal
{
protected:
    std::string _type;
    Animal(const string &);

public:
    Animal();                          // Canonical
    virtual ~Animal();                 // Canonical
    Animal(const Animal &);            // Canonical
    Animal &operator=(const Animal &); // Canonical

public:
    virtual void makeSound() const = 0;
    std::string getType() const;
};

std::ostream &operator<<(std::ostream &, const Animal &);

typedef Animal AAnimal;
