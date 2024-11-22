#include "MyClass.hpp"

MyClass::MyClass() : _attr(0)
{
    Log("[ MyClass ] Default Constructor");
}

MyClass::MyClass(const MyClass &other) : _attr(0)
{
    Log("[ MyClass ] Copy Constructor");
    *this = other;
}

MyClass &MyClass::operator=(const MyClass &other)
{
    Log("[ MyClass ] Assigment Operator");
    // Copy Here
    this->_attr = other._attr;
    return *this;
}

MyClass::~MyClass()
{
    Log("[ MyClass ] Default Destructor");
}

void MyClass::sayHello() const
{
    LogInfo("Hello from MyClass");
}
