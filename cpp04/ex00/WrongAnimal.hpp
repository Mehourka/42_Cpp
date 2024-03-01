#pragma once
#include "Common.hpp"

class WrongAnimal
{
protected:
    std::string _type;

public:
    WrongAnimal();                               //Canonical
    virtual ~WrongAnimal();                      //Canonical
    WrongAnimal(const WrongAnimal &);                 //Canonical
    WrongAnimal & operator = (const WrongAnimal &);   //Canonical
    WrongAnimal (const string &);


    void makeSound() const;

public:
    std::string getType() const;
};

std::ostream &operator<<(std::ostream &, WrongAnimal &);
