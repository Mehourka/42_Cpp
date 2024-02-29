#include "Common.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap dave("Davie");

    ClapTrap dummy("Dummy");

    // Status
    std::cout << "\n"<< dave << dummy<< "\n" << std::endl;

    dave.guardGate();
    dave.highFivesGuys();
    dave.whoAmI();
    dave.attack(dummy.getName());

    // Status
    std::cout << "\n"<< dave << dummy<< "\n" << std::endl;

}
