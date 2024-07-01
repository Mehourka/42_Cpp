#include "Common.hpp"
#include "Base.hpp"

#include <ctime>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int main(int argc, char **argv)
{

  unsigned seed = static_cast<unsigned>(std::time(NULL));
  std::srand( seed );

  Base * ptr;

  for (int i = 0; i < 5; i++)
  {
    ptr = generate();

    identify(ptr);  // Identify pointer
    identify(*ptr); // Identify reference

    std::cout << "\n" << std::endl;

    if (ptr)
      delete ptr;
  }

}

