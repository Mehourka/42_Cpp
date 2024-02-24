#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(string type) 
{
    setType(type);
}

const string&   Weapon::getType() { return type; }
void    Weapon::setType(string newType) { type = newType; }

