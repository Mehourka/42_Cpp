#include "HumanB.hpp"

HumanB::HumanB(string str)
    : Human(str){ weapon = NULL;}

HumanB::HumanB(string str, Weapon &weapon)
    : Human(str), weapon(&weapon) {}

void HumanB::setWeapon(Weapon &w) {weapon = &w;}

const string HumanB::getWeaponType()
{
    if (!weapon)
    {
        return Human::getWeaponType();
    }
    return weapon->getType();
}