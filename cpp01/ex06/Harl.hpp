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
    void invalid(void);

    void            setLevel(Harl::e_logLevel levelIdx);
    void            setLevel(string level);
    e_logLevel      getLevelIdx(string level);
    harlFnc         getComplainFnc(Harl::e_logLevel level);
    static string   toLower(string);
    void            getCurrLevel();

public:
    Harl();
    Harl(string);
    void    complain();
    void    complain(string level);
};
