#include "ClapTrap.hpp"

string ClapTrap::getUniqueName(const string target_name) const
{
    int i = 0;
    std::stringstream sstm;
    sstm << target_name;
    clap_list_t *ptr = ClapTrap::targets;
    while (ptr)
    {
        if (ptr->clap->getName() == target_name)
            i++;
        ptr = ptr->next;
    }
    if (i > 0)
        sstm << "_" << i + 1;

    return sstm.str();
}

void ClapTrap::pushTarget()
{
    clap_list_t *ptr = ClapTrap::targets;
    clap_list_t *node = new clap_list_t;

    node->clap = this;
    node->next = NULL;

    if (!ptr)
    {
        ClapTrap::targets = node;
        return;
    }
    while (ptr->next)
    {
        ptr = ptr->next;
    }
    ptr->next = node;

    return;
}

void ClapTrap::popTarget(string target_name)
{
    clap_list_t *prev, *ptr;

    ptr = ClapTrap::targets;
    if (!ptr)
        return;
    if (ptr && ptr->clap->getName() == target_name)
    {
        ClapTrap::targets = ptr->next;
        delete ptr;
        // ClapTrap::printTargets();
        return;
    }
    while (ptr)
    {
        prev = ptr;
        ptr = ptr->next;
        if (ptr && ptr->clap->getName() == target_name)
        {
            prev->next = ptr->next;
            delete ptr;
            // ClapTrap::printTargets();
            return;
        }
    }
}

ClapTrap *ClapTrap::findTarget(string target_name)
{
    clap_list_t *head;

    head = ClapTrap::targets;
    while (head)
    {
        if (head->clap->getName() == target_name)
            return head->clap;
        head = head->next;
    }
    return (NULL);
}

void ClapTrap::printTargets()
{
    clap_list_t *ptr = ClapTrap::targets;
    std::cout << "\033[32m - [Target List] : ";
    while (ptr)
    {
        std::cout << ptr->clap->getName() << ", ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}