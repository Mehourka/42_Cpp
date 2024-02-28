#pragma once
#include <iostream>
#include <string>
#include <sstream>

#define Log(x) std::cout << (x) << std::endl
#define LogInfo(x) std::cout << "\033[30m" << (x) << "\033[37m" <<  std::endl


using std::string;