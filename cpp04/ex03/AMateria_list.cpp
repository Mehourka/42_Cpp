#include "AMateria.hpp"

m_list_t * AMateria::materiaList = NULL;

void AMateria::pushMateria()
{
    m_list_t *ptr = AMateria::materiaList;
    m_list_t *node = new m_list_t;

    node->materiaPTR = this;
    node->next = NULL;

    if (!ptr)
    {
        AMateria::materiaList = node;
        return;
    }
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = node;

    return;
}

void AMateria::popMateria(AMateria *target)
{
    m_list_t *prev, *ptr;

    ptr = AMateria::materiaList;
    if (!ptr)
        return;
    if (ptr && ptr->materiaPTR == target)
    {
        AMateria::materiaList = ptr->next;
        delete ptr;
        return;
    }
    while (ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        if (ptr && ptr->materiaPTR == target)
        {
            prev->next = ptr->next;
            delete ptr;
            return;
        }
    }
}

void AMateria::printMateriaList()
{
    m_list_t *ptr = AMateria::materiaList;
    std::cout << GREEN << "- [Materia's List] : " << WHITE;
    while (ptr)
    {
        std::cout << ptr->materiaPTR->getType() << ", ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}