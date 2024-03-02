#include "Common.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << meta->getType() << " " << std::endl;

    i->makeSound(); // will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete i;
    delete j;
    delete meta;

    if (true)
    {
        std::cout << "\n\nWrong Animals :" << std::endl;

        const WrongAnimal *w_animal = new WrongAnimal();
        const WrongAnimal *w_cat = new WrongCat();

        std::cout << w_animal->getType() << " " << std::endl;
        std::cout << w_cat->getType() << " \n" << std::endl;

        w_animal->makeSound();
        w_cat->makeSound(); // will output the WrongAnimal sound!

        delete w_animal;
        delete w_cat;
    }

    return 0;
}
