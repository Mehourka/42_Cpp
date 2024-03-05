#include "MyClass.hpp"

MyClass::MyClass(): _attr(0)
{

}

MyClass::MyClass(const MyClass & other): _attr(0)
{
    *this = other;
}

MyClass& MyClass::operator=(const MyClass &other)
{
    // Copy Here
    this->_attr = other._attr;
    return *this;
}

MyClass::~MyClass()
{

}

void MyClass::sayHello() const
{
    Log("Hello from MyClass");
}

