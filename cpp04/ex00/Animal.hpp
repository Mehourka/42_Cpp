#pragma once
#include "Common.hpp"

class Animal
{
protected:
    std::string _type;

public:
    Animal();                               //Canonical
    virtual ~Animal();                      //Canonical
    Animal(const Animal &);                 //Canonical
    Animal & operator = (const Animal &);   //Canonical
    Animal(const string &);                               

    virtual void makeSound() const;

public:
    std::string getType() const;
};

std::ostream &operator<<(std::ostream &, Animal &);
