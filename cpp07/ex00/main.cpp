#include "Common.hpp"
#include "Templates.hpp"

int ft_tests(void)
{
  double a = -12;
  double b = 42.42;
  Log("\n\nInitial state: ");
  std::cout << "a=" << a << " b=" << b << std::endl;
  Log("\nSwap ...");
  swap(a, b);
  std::cout << "a=" << a << " b=" << b << std::endl;
  std::cout << "max: " << max(a, b) << std::endl;
  std::cout << "min: " << min(a, b) << std::endl;
  return 0;
}

int main( void ) {
  int a = 2;
  int b = 3;
  ::swap( a, b );
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
  std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
  std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

  ft_tests();
  return 0;
}

