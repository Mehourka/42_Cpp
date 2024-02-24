#include "HumanA.hpp"


HumanA::HumanA(string name, Weapon& weapon)
    : Human(name), _weapon(weapon) {}

const string HumanA::getWeaponType()
{
    return _weapon.getType();
}
