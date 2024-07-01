#include "Common.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <typeinfo>
#include <cstdlib>
#include <ctime>

Base * generate(void)
{
  // Generate random A, B or C instance
  Base *ptr = NULL;

  switch (std::rand() % 3)
  {
    case 0:
      ptr = new A;
      Log("Created A");
    break;
    case 1:
      ptr = new B();
      Log("Created B");
    break;
    case 2:
      ptr = new C();
      Log("Created C");
    break;
  }

  return ptr;
}

void identify(Base* p)
{
  // Identify Pointer
  if (dynamic_cast<A*>(p) != NULL)
    LogInfo("Pointer is identified as type A");
  if (dynamic_cast<B*>(p) != NULL)
    LogInfo("Pointer is identified as type B");
  if (dynamic_cast<C*>(p) != NULL)
    LogInfo("Pointer is identified as type C");
}

void identify(Base& p)
{
  // Identify Reference
  try {
    dynamic_cast<A&>(p);
    LogInfo("Reference is identified as type A");
  } catch (const std::bad_cast &e) { }

  try {
    dynamic_cast<B&>(p);
    LogInfo("Reference is identified as type B");
  } catch (const std::bad_cast &e) { }

  try {
    dynamic_cast<C&>(p);
    LogInfo("Reference is identified as type C");
  } catch (const std::bad_cast &e) { }
}

