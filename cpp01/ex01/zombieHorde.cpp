#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    Zombie *horde = new Zombie[N];
    while(N-- > 0)
        horde[N].setName(name);
   return horde;
}
