#pragma once
#include <string>
using std::string;

class Weapon
{
private:
    string type;
public:

    Weapon();
    ~Weapon();

    const string    &getType();
    void            setType(string);
};
