#include "Common.hpp"

class Zombie
{
private:
    string  nom;
    Zombie(void);

    
public:

    Zombie(string zombie_name);
    ~Zombie();

    void   announce(void);
};

