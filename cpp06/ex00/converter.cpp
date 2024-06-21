#include "Converter.hpp"

Converter::Converter(): _str("")
{
}

Converter ::Converter(const std::string &str): _str(str)
{
	this->trim_spaces();
}

Converter::~Converter()
{

}

Converter::Converter(const Converter &str)
{
	(void) str;

}

Converter & Converter::operator = (const Converter &other)
{
	this->_value = other._value;
	return *this;
}

// Checking 

bool Converter::is_int()
{
	char *end = NULL;
	long _int  = std::strtol(_str.data(), &end, 10);

	return end[0] == '\0';
}
bool Converter::is_float()
{
	char *end = NULL;
	double _float = std::strtof(_str.data(), &end);

	return end[0] == 'f' && end[1] == '\0';
}
bool Converter::is_double()
{
	char *end = NULL;
	double _double = std::strtod(_str.data(), &end);

	return end[0] == '\0';
}
bool Converter::is_char()
{
	return (_str.length() == 1 && std::isprint(_str[0]));
}

void Converter::print()
{
	std::cout << std::boolalpha\
		<< "\nRaw: " << std::quoted(_str.data()) \
		<< "\nis Char: " << this->is_char()\
		<< "\nis Int: " << this->is_int()\
		<< "\nis Float: " << this->is_float()\
		<< "\nis Double: " << this->is_double()\
		<< std::endl;
}

void Converter::trim_spaces()
{
	unsigned long i = _str.length() - 1;

	LogErr(">>");
	LogErr(_str.data()[i]);
	LogErr("<<");
	while (i > 0 && std::isspace(_str.data()[i]))
	{
		_str.replace(i, 1, "\0");
		i--;
	}

	i = 0;
	while (std::isspace(_str.data()[i]))
	{
		_str.replace(i, 1, "\0");
		i;
	}
}
