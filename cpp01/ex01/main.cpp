#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name);

int main(void)
{
    Zombie *horde;
    const int     SIZE = 3;
    const std::string   name = "Tim";

    // Create the horde
    std::cout << "\nCreating a Horde of " << SIZE << " Zombies." << std::endl;
    horde = zombieHorde(SIZE, name);

    // Check Horde
    for (int i = 0; i < SIZE; i++)
    {
        horde[i].announce();
    }
    
    // Delete Horde
    std::cout << "\nDeleting the horde ..." << std::endl;
    delete[] horde;
}

