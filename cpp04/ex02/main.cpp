#include "Common.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

#define TABLE_SIZE 100

int main(void)
{

    // Cannot instantiate Abstract Animal
    // AAnimal *nope = new AAnimal();
    // std::cout << nope->getType() << std::endl;

    Cat *cat = new Cat();
    Dog *dog = new Dog();

    std::cout << *cat << *dog << std::endl;

    delete cat;
    delete dog;
}
