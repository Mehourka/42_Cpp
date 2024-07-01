#include "Common.hpp"


template< typename T >
const T& max(const T& a,const T& b)
{
  if (a > b)
    return a;
  return b;
}


template < typename T >
const T& min(const T& a, const T& b)
{
  if (a < b)
    return a;
  return b;
}

template < typename T >
void swap(T& a, T& b)
{
  T tmp = a;
  a = b;
  b = tmp;
}

int main(void)
{
  double a = -12;
  double b = 42.42;

  Log("Initial state: ");
  std::cout << "a=" << a << " b=" << b << std::endl;
  Log("\nSwap ...");
  swap(a, b);
  std::cout << "a=" << a << " b=" << b << std::endl;

  std::cout << "max: " << max(a, b) << std::endl;
  std::cout << "min: " << min(a, b) << std::endl;
}
