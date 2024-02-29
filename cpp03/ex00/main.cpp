#include "Common.hpp"
#include "ClapTrap.hpp"

#define RED "\033[31m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define PURPLE "\033[35m"

int main(void)
{
	ClapTrap red("Red");
	ClapTrap blue("Blue");
	ClapTrap green("Green");
	ClapTrap red_2("Red");

	// Set Colors
	red.setColor(RED);
	blue.setColor(BLUE);
	green.setColor(GREEN);
	red_2.setColor(PURPLE);

	// Setting attacks
	red.setAttack(5);
	blue.setAttack(4);
	green.setAttack(5);

	// Status
	std::cout << "\n"
			  << red
			  << blue
			  << green
			  << red_2 << std::endl;

	// Fitght
	red.attack(blue.getName());
	blue.beRepaired(1);
	green.attack(blue.getName());
	blue.attack(red.getName());
	blue.takeDamage(3);
	blue.beRepaired(1);
	red.attack(blue.getName());

	for (int i = 11; i > 0; i--)
		red_2.beRepaired(1);
	red_2.attack(red.getName());

	// Status
	std::cout << "\n"
			  << red
			  << blue
			  << green
			  << red_2 << std::endl;
}
