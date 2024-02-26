#pragma once
#include <iostream>
#include <string>
using std::string;

class Harl
{
public:
    static const int HarlLevelInfo = 2;
    static const int HarlLevelWarning = 1;
    static const int HarlLevelError = 0;
private:
    int m_logLevel;
public:
        Harl();
        void SetLevel(int level);
        void error(void) const;
        void warn(void) const;
        void info(void) const;
        void debug(void) const;
};
