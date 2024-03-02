#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
    Brain *_brain;

public:
    Dog();                       // Canonical
    ~Dog();                      // Canonical
    Dog(const Dog &);            // Canonical
    Dog &operator=(const Dog &); // Canonical

    void makeSound() const;
    void addIdea(int, const std::string &);
    void printIdeas() const;
};
