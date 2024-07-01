#pragma once

#include "Common.hpp"
#include <exception>

template < typename T = char >
class Array
{

private:
  T*        _content;
  unsigned  _size;

public:
  Array(unsigned size) : _size(size) {
    _content = new T[_size]();
  }

  Array() : _size(0) {
    _content = new T[_size]();
  }

  Array(Array<T> const &A) {
    *this = A;
  }

  ~Array() {
    delete[] _content;
  }

  Array<T> & operator = (const Array<T> &other) {
    this->_size = other.size();

    // Deep Copy
    delete[] this->_content;
    this->_content = new T[_size]();
    for (unsigned i = 0; i < _size; i++)
      (*this)[i] = other[i];
    return *this;
  }

  void check_access(unsigned i) const {
    if ( i >= _size )
      throw ForbiddenAccess();
  }

  T   operator [] (unsigned i) const // Get with bracket
  {
    check_access(i);
    return this->_content[i];
  }

  T&  operator [] (unsigned i) // Set with bracket
  {
    check_access(i);
    return this->_content[i];
  }

  unsigned size() const { 
    return _size; 
  }
   
  class ForbiddenAccess : std::exception
  {
  public:
    const char* what() const throw() { return "[ForbiddenAccess] Invalid Index";}
  };
};


template < typename T >
std::ostream & operator << (std::ostream & o, const Array<T> &array)
{
  o << "Array: ";
  for (unsigned i = 0; i < array.size(); ++i)
    o << array[i] << " ";
  o << std::endl;
  return o;
}

