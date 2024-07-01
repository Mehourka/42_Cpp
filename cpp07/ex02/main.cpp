#include "Array.hpp"

void test_copy(const Array<int> &A)
{
  Array<int> B(3);
  std::cout << "Testing deep copy" << std::endl;
  std::cout << "B - " << B << std::endl;
  B = A;
  B[0] = 42;
  std::cout << "A - " << A << std::endl;
  std::cout << "B - " << B << std::endl;
}

int main(void)
{
  try {
    int size = 5;
    Array<int> A(size);

    // Create An array
    for (int i = 0; i < size; ++i)
    {
      A[i] = i * 2;
    }
    std::cout << A << std::endl;
    // Copy an Array

    // Access an element (change index for testing)
    int index = 1;
    std::cout << "A[" << index << "] = " << A[index] <<std::endl;

    test_copy(A);
  } catch (const Array<int>::ForbiddenAccess &e) {
    LogErr(e.what()); 
  }
}

