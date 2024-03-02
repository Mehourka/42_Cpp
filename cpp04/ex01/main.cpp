#include "Common.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define TABLE_SIZE 100

int main(void)
{
    // Create Table
    Animal *table[TABLE_SIZE];

    // Populate Table
    std::cout << "\nCreating Animal table of size : " << TABLE_SIZE << std::endl;
    for(int i = 0; i < TABLE_SIZE; i++)
    {
        if (i <= (TABLE_SIZE / 2) - 1)
            table[i] = new Dog();
        else
            table[i] = new Cat();
    }
    // Delete table ANIMALS
    std::cout << "Deleting Animal table" << std::endl;
    for(int i = 0; i < TABLE_SIZE; i++)
        delete table[i];


    // Brain Deep Copy Test
    if (false) // Switch to true
    {
        Cat *catA = new Cat();
        Cat *catB;

        catA->addIdea(1, "Find Human pet");
        catA->addIdea(2, "Get fed by Human pet");

        catB = new Cat(*catA); // Deep copy Here

        catA->addIdea(3, "Snob Human pet");
        catB->addIdea(3, "Purrrrr");

        catA->printIdeas();
        catB->printIdeas();

        delete catA;
        delete catB;
    }

}
