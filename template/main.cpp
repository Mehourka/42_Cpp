#include <iostream>
#include "Common.hpp"
#include "MyClass.hpp"


int main(void)
{
    std::string str = "Hello World!";
    Log(str);

    MyClass *pew = new MyClass();

    std::cout << "WADUUUU" << std::endl;
    pew->sayHello();
    delete pew;
}
