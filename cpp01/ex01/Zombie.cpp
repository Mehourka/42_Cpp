#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::Zombie(string zombie_name)
{
    nom = zombie_name;
}

Zombie::~Zombie()
{
    std::cout << this->nom << " Has been slain !!!" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->nom << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
    nom = name;
}
