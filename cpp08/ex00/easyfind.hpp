#include <exception>
#include <iostream>
#include <cstdlib>

class ElementNotFound : public std::exception
{
	char const *what() const throw() {return "Element not found.";}
};

template <typename T>
typename T::iterator easyfind(T &collection, int target)
{
	typename T::iterator it;
	int pos = 0;
	for (it = collection.begin(); it != collection.end(); ++it)
	{
		if (*it == target)
			return it;
		++pos;
	}
	throw ElementNotFound();
}

template <typename T>
void print_iterator(T &collection)
{
	typename T::iterator it;
	std::cout << "[";
	for (it = collection.begin(); it != collection.end(); ++it) {
		std::cout << *it << ",";
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void test_easyfind(T &collection)
{
	typename T::iterator pos;

	print_iterator(collection);
	for (int i = 0; i < 10; i++)
	{
		int target = std::rand() % 20;
		try {
			pos = easyfind(collection, target);
			std::cout << " - " << *pos << " found at position " << std::distance(collection.begin(), pos)<< std::endl;
		} catch (ElementNotFound &) {
			std::cout << " - " << target << " not found"<< std::endl;
		}
	}
}
