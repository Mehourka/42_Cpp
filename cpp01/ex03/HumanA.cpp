#include "HumanA.hpp"


HumanA::HumanA(string str, Weapon& weapon)
    : Human(str), weapon(weapon) {}

const string HumanA::getWeaponType()
{
    return weapon.getType();
}