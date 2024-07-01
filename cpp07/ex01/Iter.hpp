#include <cctype>
#include "Common.hpp"

template< typename Tab, typename Size, typename Fnc >
void iter(Tab *t, Size size, Fnc fnc)
{
  for (int i = 0; i < size; ++i)
  {
    t[i] = fnc(t[i]);
  }
}


template <typename T>
T ft_double(T a)
{
  return (2 * a);
}
