#include <Weapon.hpp>

Weapon::Weapon() {};
Weapon::~Weapon() {};

const string&    Weapon::getType()
{
    return type;
}
void    setType(string newType)
{
    type = newType;
}

