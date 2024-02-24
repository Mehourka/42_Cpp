#pragma once
#include <string>
using std::string;

class Weapon
{
private:
    string type;

public:
    Weapon();
    Weapon(string);
    ~Weapon();

    const string    &getType();
    void            setType(string);
};
