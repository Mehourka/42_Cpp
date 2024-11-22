#include <iostream>
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <ctime>

int main(void)
{
	std::vector<int> v;
	std::list<int> l;
	std::srand(static_cast<unsigned int >(std::time(NULL)));

	for (int i = 0; i <= 10; i++) {
		v.push_back(i * 2);
		l.push_back(i * 3);
	}



	std::cout << "Testing Vecor: " << std::endl;
	test_easyfind(v);

	std::cout << "\n\nTesting List: " << std::endl;
	test_easyfind(l);

	std::vector<int> empty_vec;
	std::cout << "\n\nTesting Empty Vector: " << std::endl;
	test_easyfind(empty_vec);

	return 0;
}
