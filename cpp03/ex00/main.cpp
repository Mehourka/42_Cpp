#include "Common.hpp"
#include "ClapTrap.hpp"
int main(void)
{
	ClapTrap red("Red");
	ClapTrap blue("Blue");

	std::cout << red;
	std::cout << ClapTrap::dummy;

	red.setAttack(2);
	red.attack("Blue");

	std::cout << red;
	std::cout << ClapTrap::dummy;

}
