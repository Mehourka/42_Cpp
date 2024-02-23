#include "Zombie.hpp"

int main(void)
{
    // Zombie on the heap
    Zombie bob("Bob");
    bob.announce();

    // newZombie in the Stack
    Zombie *carl = Zombie::newZombie("Carl");
    carl->announce();
    delete carl;

    // Zombie inside function scope
    Zombie::randomChump("Bill"); 
}

