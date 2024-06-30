#pragma once

#include "Common.hpp"
#include <exception>
#include <climits>

class Converter {
private:

  enum Type{
    NoType = 0,
    Char,
    Int,
    Float,
    Double
  };
	std::string	_str;
	double	_dvalue;
	Type	_type;

public:
	Converter(); // Canonical
	~Converter(); // Canonical
	Converter(const Converter &); // Canonical
	Converter & operator = (const Converter &); // Canonical

	Converter(const std::string &);

	bool is_int();
	bool is_float();
	bool is_double();
	bool is_char();

  std::string convert(int i);
  std::string convert(double d);
  std::string convert(float f);
  std::string convert(char c);

  operator char() const;
  operator int() const;
  operator float() const;
  operator double() const;

	void print();

private:
	void trim_spaces();

public:
  // Error handeling
  class InvalidConversion : std::exception
  {
  public:
    virtual const char* what() const throw();
  };

  class InvalidLiteral : std::exception
  {
  public:
    virtual const char* what() const throw();
  };
};
