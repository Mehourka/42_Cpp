#include "Harl.hpp"

Harl::Harl() { setLevel(""); }

Harl::Harl(string level)
{
    setLevel(getLevelIdx(level));
}

void Harl::error(void)
{
    std::cout
        << "[ ERROR ]\nThis is unacceptable ! I want to speak to the manager now.\n"
        << std::endl;
}

void Harl::warn(void)
{
    std::cout
        << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming\
for years whereas you started working here since last month.\n"
        << std::endl;
}

void Harl::info(void)
{
    std::cout
        << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put\
enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n"
        << std::endl;
}

void Harl::debug(void)
{
    std::cout
        << "[ DEBUG ]\nI love having extra bacon for my \
7XL-double-cheese-triple-pickle-special-\
ketchup burger. I really do !\n"
        << std::endl;
}

void Harl::invalid(void)
{
    std::cout
        << "[ Probably complaining about insignificant problems ]"
        << std::endl;
}

harlFnc Harl::getComplainFnc(Harl::e_logLevel levelIdx)
{
    switch (levelIdx)
    {
    case Error:
        return &Harl::error;

    case Warning:
        return &Harl::warn;

    case Info:
        return &Harl::info;

    case Debug:
        return &Harl::debug;

    default:
        return NULL;
    }

    return NULL;
}

string Harl::toLower(string str)
{
    for (string::size_type i = 0; i < str.size(); i++)
    {
        str[i] = std::tolower((int)str[i]);
    }
    return str;
}

Harl::e_logLevel Harl::getLevelIdx(string level)
{
    level = Harl::toLower(level);
    if (level == "error")
        return Error;
    if (level == "warning")
        return Warning;
    if (level == "info")
        return Info;
    if (level == "debug")
        return Debug;
    return Invalid;
}

void Harl::setLevel(string level)
{
    m_logLevel = getLevelIdx(level);
}

void Harl::setLevel(Harl::e_logLevel level)
{
    m_logLevel = level;
}

void Harl::getCurrLevel()
{
    std::cout << "Current Harl level: " << m_logLevel << std::endl;
}

void Harl::complain()
{
    switch (m_logLevel)
        {
        case Error:
            error();
            break;
        case Warning:
            warn();
            error();
            break;
        case Info:
            info();
            warn();
            error();
            break;
        case Debug:
            debug();
            info();
            warn();
            error();
            break;

        default:
            invalid();
            break;
        }
}

void Harl::complain(string level)
{
    // harlFnc complain_fnc;

    setLevel(level);
    complain();
}
