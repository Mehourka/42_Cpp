#include "Common.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap dave("Davie");

    ScavTrap steve("Steve");
    ClapTrap dummy("Dummy");
    FragTrap fred("Fred");

    // Status
    std::cout << "\n"<< dave << dummy << fred << steve<<  "\n" << std::endl;

    dave.guardGate();
    dave.highFivesGuys();
    dave.whoAmI();
    dave.attack(dummy.getName());
    

    // Enery tests
    if (false)
    {
        for (int i = 0; i < 50; i++)
            dave.guardGate();
        dave.guardGate();
        dave.highFivesGuys();
        dave.whoAmI();
        dave.attack(dummy.getName());
    }
    
    // Status
    std::cout << "\n"<< dave << dummy<< "\n" << std::endl;

}
