#include "Converter.hpp"
#include <iomanip>

Converter::Converter(): _str("")
{
}

Converter ::Converter(const std::string &str): _str(str)
{
	this->trim_spaces();
  if (is_int())
  {
    convert(
      static_cast<int>(std::strtol(_str.data(), NULL, 10))
    );
  }
  else if(is_char())
  {
   convert(_str[0]);
  }
  else if (is_double())
  {
    convert(std::strtod(_str.data(), NULL));
  }
  else if (is_float())
  {
    convert(std::strtof(_str.data(), NULL));
  }
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

void Converter::convert(int i)
{
  std::cout << "Converting an INT" << std::endl;
}

void Converter::convert(double lit)
{
  std::cout << "Converting a DOUBLE" << std::endl;
}

void Converter::convert(float f)
{
  std::cout << "Converting a FLOAT" << std::endl;
}

void Converter::convert(char c)
{
  std::cout << "Converting a CHAR" << std::endl;
}


void Converter::print()
{
  std::cout << std::boolalpha\
		<< "\nInput: " << "\"" << _str.data() << "\"" \
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
