#pragma once
#include "Common.hpp"

class Animal
{
protected:
    std::string _type;

public:
    Animal();                               //Canonical
    ~Animal();                              //Canonical
    Animal(const Animal &);                 //Canonical
    Animal & operator = (const Animal &);   //Canonical

    void makeSound();

public:
    std::string getType() const;
};

std::ostream &operator<<(std::ostream &, Animal &);
