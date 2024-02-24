#include "Weapon.hpp"
#include <iostream>

int main(void)
{
    Weapon sword;

    sword.setType("Short Sword");

    const string&  swordREF = sword.getType();

    std::cout << "You found: a (" << swordREF << ")" << std::endl;

    sword.setType("Broadsword +1");
    std::cout << "You upgraded your sword to: (" << swordREF << ")" << std::endl;
}

