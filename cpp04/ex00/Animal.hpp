#pragma once
#include "Common.hpp"

class Animal
{
    Animal();                               //Canonical
    ~Animal();                              //Canonical
    Animal(const Animal &);                 //Canonical
    Animal & operator = (const Animal &);   //Canonical


};

std::ostream &operator<<(std::ostream &, Animal &);
