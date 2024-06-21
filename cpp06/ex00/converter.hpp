#pragma once

#include "Common.hpp"

enum e_Type{
	_char,
	_int,
	_float,
	_double
};

class Converter {
private:
	std::string	_str;
	void	*_value;
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

	void print();

private:
	void trim_spaces();

	// is_char();
	// is_int();
	
};
