#include <iostream>
#include "Common.hpp"
#include "Bureaucrat.hpp"


int main(void)
{
    std::string str = "Hello World!";
    LogInfo(str);

    Bureaucrat *pew = new Bureaucrat();

    pew->sayHello();
    delete pew;
}
