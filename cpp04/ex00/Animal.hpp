#pragma once
#include "Common.hpp"

class Animal
{
protected:
    std::string _type;

public:
    Animal();                               //Canonical
    virtual ~Animal();                              //Canonical
    Animal(const Animal &);                 //Canonical
    Animal & operator = (const Animal &);   //Canonical

    virtual void makeSound() const;

public:
    virtual std::string getType() const;
};

std::ostream &operator<<(std::ostream &, Animal &);
