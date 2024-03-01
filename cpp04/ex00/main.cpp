#include "Common.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // Animal A;
    // Cat C;
    // Dog D;

    // std::cout << A << C << D;

    // A.makeSound();
    // C.makeSound();
    // D.makeSound();

    // // std::cout << D.getType();


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
}
