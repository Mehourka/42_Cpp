#pragma once
#include "Common.hpp"

class MyClass
{
private:
    int _attr;

public:
    MyClass();
    MyClass(const MyClass &);
    MyClass &operator=(const MyClass &);
    ~MyClass();

    void sayHello() const;
};
