#include <iostream>
#include "Common.hpp"
#include "MyClass.hpp"

int main(void)
{
    std::string str = "Hello World!";
    LogInfo(str);

    MyClass *pew = new MyClass();

    pew->sayHello();
    delete pew;
}
