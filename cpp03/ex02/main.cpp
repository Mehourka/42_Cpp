#include "Common.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap frank("Frank"); // Purple
    // ScavTrap stan("Stan"); // Purple
    // stan.setColor("\033[31m");

    ClapTrap carl("Carl"); // Blue

    // // Status
    // std::cout << "\n" << steve << carl << stan << "\n";

    frank.highFivesGuys();
    frank.attack(carl.getName());
    std::cout << frank;

    // // Set attacks
    // stan.setAttack(95);
    // carl.setAttack(2);

    // carl.attack(steve.getName());

    // steve.attack(carl.getName());
    // stan.attack(steve.getName());
    // steve.beRepaired(1);

    // std::cout << steve << carl << stan << "\n";

    // stan.attack(steve.getName());
    // carl.attack(steve.getName());
    // steve.beRepaired(100);
    // steve.attack(carl.getName());


    // // Status
    // std::cout << "\n" << steve << carl << stan << "\n";

    // ScavTrap::printTargets();
}
