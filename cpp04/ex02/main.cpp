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

    AAnimal *cat = new Cat();
    AAnimal *dog = new Dog();

    std::cout << *cat << *dog << std::endl;
    cat->makeSound();
    dog->makeSound();

    delete cat;
    delete dog;
}
