#include "Harl.hpp"

Harl::Harl() {}

void Harl::error(void)
{
    std::cout
        << "[Error]\t  This is unacceptable ! I want to speak to the manager now."
        <<  std::endl;
}

void Harl::warn(void)
{
    std::cout
        << "[Warning] I think I deserve to have some extra bacon for free. I’ve been coming\
for years whereas you started working here since last month."
        <<  std::endl;
}

void Harl::info(void)
{
    std::cout
        << "[Info]\t  I cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
        <<  std::endl;
}


void Harl::debug(void)
{
    std::cout
        << "[Debug]\t  I love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do !"
        <<  std::endl;
}

harlFnc Harl::getComplainFnc(string level)
{
    if (level == "error") return &Harl::error;
    if (level == "warn") return &Harl::warn;
    if (level == "info") return &Harl::info;
    if (level == "debug") return &Harl::debug;
    return NULL;
}

void Harl::complain(string level)
{
    harlFnc complain_fnc;

    complain_fnc = getComplainFnc(level);

    if (complain_fnc != NULL)
        (this->*complain_fnc)();
}

