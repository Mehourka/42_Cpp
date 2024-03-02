#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *_brain;

public:
    Cat();                       // Canonical
    ~Cat();                      // Canonical
    Cat(const Cat &);            // Canonical
    Cat &operator=(const Cat &); // Canonical

    void makeSound() const;
    void addIdea(int, const std::string &);
    void printIdeas() const;
};
