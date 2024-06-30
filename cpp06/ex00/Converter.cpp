#include "Converter.hpp"
#include <cfloat>
#include <cmath>
#include <iomanip>

// ==================
// Canonical Form
// ==================

Converter::Converter(): _str(""), _type(NoType)
{
}

Converter::~Converter()
{
}

Converter::Converter(const Converter &other)
{
  *this = other;
}

Converter & Converter::operator = (const Converter &other)
{
	this->_dvalue = other._dvalue;
	return *this;
}


// ==================
// Main Constructor
// ==================

Converter ::Converter(const std::string &str): _str(str), _type(NoType)
{

  const char *cstr = str.c_str();

	this->trim_spaces();
  if (is_int())
  {
    _type = Int;
    _dvalue = static_cast<double>( strtol(cstr, NULL, 10) );
  }
  else if(is_char())
  {
    _type = Char;
    _dvalue = static_cast<double>( cstr[0] );
  }
  else if (is_double())
  {
    _type = Double;
    _dvalue = static_cast<double>( std::strtod(cstr, NULL) );
  }
  else if (is_float())
  {
    _type = Float;
    _dvalue = static_cast<double>( std::strtof(cstr, NULL) );
  }
  
  if (_type == NoType)
    throw Converter::InvalidLiteral();
}



// ==================
// Type Checks
// ==================

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

// ==================
// Conversions
// ==================

std::string Converter::convert(char c)
{
  std::ostringstream oss;
  if (_dvalue > CHAR_MAX || _dvalue < CHAR_MIN || _dvalue != _dvalue )
    return ("Impossible");
  if (!std::isprint(c))
    return "Not Displayable";
  oss << c;
  return oss.str();
}

std::string Converter::convert(int i)
{
  if (_dvalue > INT_MAX || _dvalue <= INT_MIN || _dvalue != _dvalue)
    return ("Impossible");
  std::ostringstream oss;
  oss << i;
  return oss.str();
}

std::string Converter::convert(float f)
{
  if (!std::isinf(f) &&  std::abs(f) > FLT_MAX)
  {
      return ("Impossible");
  }
  std::ostringstream oss;

  float tmp;
  if (std::modf(f, &tmp) == 0)
    oss << std::fixed << std::setprecision(1);
  oss << f << "f";
  return oss.str();
}

std::string Converter::convert(double d)
{
  if (!std::isinf(d) && std::abs(d) > DBL_MAX)
  {
      return ("Impossible");
  }
  std::ostringstream oss;
  
  double tmp;
  if (std::modf(d, &tmp) == 0)
    oss << std::fixed << std::setprecision(1);

  oss << d; 
  return oss.str();
}

Converter::operator char() const
{
  return static_cast<char>(_dvalue);
}

Converter::operator int() const
{
  return static_cast<int>(_dvalue);
}

Converter::operator float() const
{
  return static_cast<float>(_dvalue);
}

Converter::operator double() const
{
  return _dvalue;
}



// ==================
// Printing
// ==================

void Converter::print()
{
  std::cout\
		<< "\nChar: " << convert( static_cast<char>(*this) )\
		<< "\nInt: " << convert( static_cast<int>(*this) )\
		<< "\nFloat: " << convert( static_cast<float>(*this) )\
		<< "\nDouble: " << convert( static_cast<double>(*this) )\
		<< "\n\n" << std::endl;
}

void Converter::trim_spaces()
{
	unsigned long i = _str.length() - 1;

	while (i > 0 && std::isspace(_str.data()[i]))
	{
		_str.replace(i, 1, "\0");
		i--;
	}

	i = 0;
	while (std::isspace(_str.data()[i]))
	{
		_str.replace(i, 1, "\0");
		++i;
	}
}


// ==================
// Errors
// ==================

const char* Converter::InvalidLiteral::what() const throw()
{
  return ("Input is not a valid int|char|float|double Literla");
}


