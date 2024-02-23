#include "Zombie.hpp"

Zombie::Zombie(string zombie_name)
{
    nom = zombie_name;
}

Zombie::~Zombie()
{
    std::cout << this->nom << " Has fallen." << std::endl;
}

void Zombie::announce()
{
    std::cout << this->nom << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


