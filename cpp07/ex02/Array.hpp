#pragma once

#include "Common.hpp"
#include <exception>

template < typename T = char >
class Array
{

private:
  T*        _content;
  int  _size;

public:
  Array(int size) : _size(size) {
    _content = new T[_size]();
  }

  Array() : _size(0) {
    _content = new T[_size]();
  }

  Array(Array<T> const &A) : _size(0){
    _content = new T[_size]();
    *this = A;
  }

  ~Array() {
    delete[] _content;
  }

  Array<T> & operator = (const Array<T> &other) {
    this->_size = other.size();

    // Deep Copy
	if (this->_content)
    	delete[] this->_content;
    this->_content = new T[_size]();
    for (int i = 0; i < _size; i++)
      (*this)[i] = other[i];
    return *this;
  }

  void check_access(int i) const {
    if ( i >= _size || i < 0)
		throw ForbiddenAccess();
  }

  T   operator [] (int i) const // Get with bracket
  {
    check_access(i);
    return this->_content[i];
  }

  T&  operator [] (int i) // Set with bracket
  {
    check_access(i);
    return this->_content[i];
  }

  int size() const { 
    return _size; 
  }
   
  class ForbiddenAccess : public std::exception
  {
  public:
    const char* what() const throw() { return "[ForbiddenAccess] Invalid Index";}
  };
};


template < typename T >
std::ostream & operator << (std::ostream & o, const Array<T> &array)
{
  o << "Array: ";
  for (int i = 0; i < array.size(); ++i)
    o << array[i] << " ";
  o << std::endl;
  return o;
}

