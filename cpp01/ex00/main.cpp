#include "Zombie.hpp"
#define Log(x) std::cout << x << std::endl

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);

int main(void)
{
    // Zombie on the heap
    Zombie bob("Bob");
    bob.announce();

    // newZombie in the Stack
    Zombie *carl;
    carl = newZombie("Carl");
    carl->announce();
    delete carl;

    // Zombie inside function scope
    randomChump("Bill"); 
}

