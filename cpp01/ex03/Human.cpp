#include "Human.hpp"

Human::Human() {}
Human::Human(string name): name(name) {}
Human::~Human() {}

const string Human::getWeaponType(){return "BareHands";}

string Human::getName() {return name;}

void Human::attack()
{
    std::cout
        << getName()
        << " attacks with their "
        << getWeaponType() << std::endl;
}


