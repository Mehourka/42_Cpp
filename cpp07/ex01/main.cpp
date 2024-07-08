#include "Common.hpp"
#include "Iter.hpp"

char ft_toupper(const char c)
{
  if (c >= 'a' && c <= 'z')
    return c + 'A' - 'a';
  return c;
}

int main(void)
{
  char str[42] = "some text.";
  int size = 10;
  Log("Initial: ");
  std::cout << str << std::endl;
  iter(str, size, ft_toupper);
  Log("Result:");
  std::cout << str << std::endl;


  int numbers[5] = {1, 2, 3, 4, 5};
  size = 5;
  Log("\n\nInitial: ");
  for( int i = 0; i < size; ++i) std::cout << numbers[i] << " ";
  iter(numbers, size, ft_double<int>);
  Log("\nResult:");
  for( int i = 0; i < size; ++i) std::cout << numbers[i] << " ";

}

