#pragma once
#include <iostream>
#include <string>
#include <sstream>

#define GRAY "\033[30m"
#define BLUE "\033[33m"
#define GREEN "\033[32m"
#define WHITE "\033[37m"

#define _LOG true

#define Log(x) \
	if (_LOG)  \
	std::cout << GRAY << (x) << WHITE << std::endl

#define LogInfo(x) std::cout << WHITE << (x) << WHITE << std::endl

using std::string;
