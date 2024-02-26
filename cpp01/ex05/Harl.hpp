#pragma once
#include <iostream>
#include <string>
using std::string;

class Harl;

typedef void (Harl::*harlFnc)(void);

class Harl
{
private:
    int m_logLevel;
    void error(void);
    void warn(void);
    void info(void);
    void debug(void);

    harlFnc getComplainFnc(string level);

public:
    Harl();
    void complain(string level);
};
