#pragma once
#include <iostream>
#include <string>
using std::string;

class Zombie
{
private:
    string  nom;

public:

    Zombie();
    Zombie(string zombie_name);
    ~Zombie();

    void    setName(std::string name);
    void    announce(void);
};

