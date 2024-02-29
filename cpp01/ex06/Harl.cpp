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

    string commands[4] = {"error", "warning", "info", "debug"};
    Harl::e_logLevel logLvl[4] = {Error, Warning, Info, Debug};

    for (int i = 0; i < 4; i++)
    {
        if (level == commands[i])
            return logLvl[i];
    }
    return Invalid;
}

void Harl::setLevel(string level)
{
    setLevel(getLevelIdx(level));
}

void Harl::setLevel(Harl::e_logLevel level)
{
    m_logLevel = level;
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
    setLevel(level);
    complain();
}
