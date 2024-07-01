#include "Array.hpp"

int main(void)
{
  int size = 5;
  Array<int> A(size);

  for (int i = 0; i < size; ++i)
  {
    A[i] = i * 2;
    std::cout << A[i] << std::endl;
  }

  int i = 1;
  try {
    std::cout << "A[" << i << "] = " << A[i] <<std::endl;
  } catch (const Array<int>::ForbiddenAccess &e) {
    LogErr(e.what()); 
  }
}

