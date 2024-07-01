#pragma once

#include "Common.hpp"
#include <exception>

template < typename T = char >
class Array
{
public:
  T*        _content;
  unsigned  _size;

public:
  Array(unsigned size) : _size(size)
  {
    _content = new T[_size];
  }
  // Canonical
  Array() : _size(0)
  {
    Log("Default Constructor");
    _content = new T[_size];
  }
  Array(Array<T> const &A) {
    Log("Array Copy Constructor");
    *this = A;
  }
  ~Array() {
    Log("Array Destructor");
    delete[] _content;
  }
  Array<T> & operator = (const Array<T> &other) {
    Log("Array equality override");
    LogErr("Unimplemented Deep Copy"); 
    // Deep Copy
    return *this;
  }

  void check_access(unsigned i) const
  {
    if ( i >= _size )
      throw ForbiddenAccess();
  }

  T   operator [] (unsigned i) const // Get with bracket
  {
    check_access(i);
    return this->_content[i];
  }

  T&  operator [] (int i) // Set with bracket
  {
    check_access(i);
    return this->_content[i];
  }
   
  class ForbiddenAccess : std::exception
  {
  public:
    const char* what() const throw() { return "[Error] Invalid Index";}
  };
};
