#pragma once
#include <iostream>
#include <string>

using std::string;

class Zombie
{
private:
    string  nom;
    Zombie(void);

public:

    Zombie(string zombie_name);
    ~Zombie();

    static Zombie*  newZombie(std::string name);
    static void     randomChump(std::string name);

    void   announce(void);
};

