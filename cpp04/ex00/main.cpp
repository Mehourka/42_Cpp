#include "Common.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;


    if (true)
    {
        std::cout << "\n\nWrong Animals : \n" << std::endl;

        const WrongAnimal *w_animal = new WrongAnimal();
        const WrongAnimal *w_cat = new WrongCat();

        std::cout << w_animal->getType() << " " << std::endl;
        std::cout << w_cat->getType() << " " << std::endl;
        w_animal->makeSound(); //will output the WrongAnimal sound!
        w_cat->makeSound();

        delete w_animal;
        delete w_cat;
    }

    return 0;
}