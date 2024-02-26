#include "Harl.hpp"

Harl::Harl() {}

void Harl::error(string str) const
{
    std::cout 
        << "This is unacceptable ! I want to speak to the manager now."
        <<  std::endl;
}

void Harl::warn(string str) const
{
    std::cout 
        << "I think I deserve to have some extra bacon for free. I’ve been coming\
            for years whereas you started working here since last month."
        <<  std::endl;
}

void Harl::info(string str) const
{
    std::cout 
        << "I cannot believe adding extra bacon costs more money. You didn’t put\
            enough bacon in my burger ! If you did, I wouldn’t be asking for more !"    
        <<  std::endl;
}

void Harl::debug(string str) const
{
    std::cout 
        << "I love having extra bacon for my \
            7XL-double-cheese-triple-pickle-special-\
            ketchup burger. I really do !" 
        <<  std::endl;
}
