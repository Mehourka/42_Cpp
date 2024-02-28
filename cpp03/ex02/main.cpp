#include "Common.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap steve("Steve"); // Purple
    ScavTrap stan("Stan"); // Purple
    stan.setColor("\033[31m");

    ClapTrap carl("Carl"); // Blue

    // Status
    std::cout << "\n" << steve << carl << stan << "\n";

    // Set attacks
    stan.setAttack(95);
    carl.setAttack(2);

    carl.attack(steve.getName());

    steve.attack(carl.getName());
    stan.attack(steve.getName());
    steve.beRepaired(1);

    std::cout << steve << carl << stan << "\n";

    stan.attack(steve.getName());
    carl.attack(steve.getName());
    steve.beRepaired(100);
    steve.attack(carl.getName());


    // Status
    std::cout << "\n" << steve << carl << stan << "\n";

    ScavTrap::printTargets();
}
