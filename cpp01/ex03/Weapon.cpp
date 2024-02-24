#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

const string&   Weapon::getType() { return type; }
void    Weapon::setType(string newType) { type = newType; }

