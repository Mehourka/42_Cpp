#include <iostream>
#include <vector>

#include "MutantStack.hpp"


void test_vector_stack() {

	typedef MutantStack< int, std::vector<int> > stack_type;
	stack_type mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(32);
	mstack.push(64);
	mstack.push(128);

	for (stack_type::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "========================" << std::endl;
}

void test_deque_stack() {
	typedef MutantStack<std::string> stack_type;
	stack_type mstack;

	mstack.push("Hello, ");
	mstack.push("World!");
	mstack.push("This test");
	mstack.push("Iterates over a");
	mstack.push("deque<string> based stack!!");

	for (stack_type::iterator it = mstack.begin(); it != mstack.end(); ++it) {
		std::cout << *it << std::endl;
	}
	std::cout << "========================" << std::endl;

}

int main() {

	test_vector_stack();
	test_deque_stack();

}
