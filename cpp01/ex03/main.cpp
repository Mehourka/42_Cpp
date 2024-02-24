#include "Weapon.hpp"
#include <iostream>

int main(void)
{
    Weapon sword;

    sword.setType("sword");

    const string&  swordREF = sword.getType();
    
    std::cout << "You found: a (" << swordREF << ")" << std::endl;
}

