#pragma once
#include <iostream>
#include <string>
#include <sstream>

# define GRAY "\033[30m"
# define BLUE "\033[33m"
# define GREEN "\033[32m"
# define WHITE "\033[37m"

#define Log(x) std::cout << GRAY << (x) << WHITE << std::endl
#define LogInfo(x) std::cout << "\033[30m" << (x) << "\033[37m" <<  std::endl



using std::string;
