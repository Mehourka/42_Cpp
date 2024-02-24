#include "Human.hpp"

Human::Human() {}
Human::Human(string name): _name(name) {}
Human::~Human() {}

string Human::getName() {return _name;}

const string Human::getWeaponType()
{
    return "Fists";
}

void Human::attack()
{
    std::cout
        << getName()
        << " attacks with their "
        << getWeaponType() << std::endl;
}
