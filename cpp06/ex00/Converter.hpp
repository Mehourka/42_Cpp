#pragma once

#include "Common.hpp"
#include <exception>

enum e_Type{
	_char,
	_int,
	_float,
	_double
};

class Converter {
private:
	std::string	_str;
	double	*_dvalue;
	e_Type	_type;

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


  void convert(int i);
  void convert(double d);
  void convert(float f);
  void convert(char c);

  operator float() const
  {
    return 0.42f;
  }

	void print();

private:
	void trim_spaces();

	// is_char();
	// is_int();

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
