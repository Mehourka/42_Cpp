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
    std::cout <<"\n"
              << GREEN << "- [Materia's List] : " << WHITE << std::endl;
    while (ptr)
    {
        std::cout << ptr->materiaPTR->getType()
                  << " - " << ptr->materiaPTR << ")"
                  << " - Owner:" << ptr->materiaPTR->getOwner() << std::endl;
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

void AMateria::deleteUnequipedMaterias()
{
    m_list_t *ptr = AMateria::materiaList;
    AMateria *m;
    while (ptr)
    {

        m = ptr->materiaPTR;
        ptr = ptr->next;
        if (m->getOwner() == NULL)
        {
            m->popMateria(m);
            delete m;
        }
    }
}
