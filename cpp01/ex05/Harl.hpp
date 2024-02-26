#pragma once
#include <iostream>
#include <string>
using std::string;

class Harl;

typedef void (Harl::*harlFnc)(void);

class Harl
{
private:

    enum e_logLevel
    {
        Error,
        Warning,
        Info,
        Debug,
        Invalid
    };

    int m_logLevel;
    void error(void);
    void warn(void);
    void info(void);
    void debug(void);

    static string   toLower(string);
    harlFnc     getComplainFnc(string level);
    e_logLevel  getLevelIdx(string level);

public:
    Harl();
    void complain(string level);
};
