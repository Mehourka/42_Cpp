#pragma once
#include "Common.hpp"

class WrongAnimal
{
protected:
    std::string _type;
    WrongAnimal(const string &);

public:
    WrongAnimal();                               // Canonical
    virtual ~WrongAnimal();                      // Canonical
    WrongAnimal(const WrongAnimal &);            // Canonical
    WrongAnimal &operator=(const WrongAnimal &); // Canonical

public:
    void makeSound() const;
    std::string getType() const;
};

std::ostream &operator<<(std::ostream &, const WrongAnimal &);
