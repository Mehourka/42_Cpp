#include "HumanB.hpp"

HumanB::HumanB(string name): Human(name)
{
     _weapon = NULL;
}

HumanB::HumanB(string name, Weapon &weapon)
    : Human(name), _weapon(&weapon) {}

void HumanB::setWeapon(Weapon &weapon)
{
    _weapon = &weapon;
}

const string HumanB::getWeaponType()
{
    if (!_weapon)
    {
        return Human::getWeaponType();
    }
    return _weapon->getType();
}
