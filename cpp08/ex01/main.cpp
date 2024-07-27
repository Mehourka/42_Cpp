#include <iostream>

#include "Span.hpp"

void test_spans();
void test_max_size();
void test_negative_spans();
void test_insert_range();

int main() {
	// test_spans();
	// test_max_size();
	// test_negative_spans();
	test_insert_range();
}

void test_spans() {
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);;
	std::cout << "Data: " << sp << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void test_max_size()
{
	Span a(5);

	// Copy max num of elemnts
	for (int i = 0; i < 5; i++) {
		a.addNumber(0);
	}
	// Try and copy one more throws an error
	try {
		a.addNumber(1);
	} catch (Span::SpanOverflow &e) {
		std::cerr << "[Caught Error] " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void test_negative_spans() {
	Span sp = Span(10);
	sp.addNumber(-10);
	sp.addNumber(-20);
	sp.addNumber(-2);
	std::cout << "Data: " << sp << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
}

void test_insert_range()
{
	// Create vector
	std::vector<int> input;
	for (int i = 0; i < 6; i++) {
		input.push_back(i * i);
	}
	// Copy data from vector
	Span span(6);
	try {
		span.insert_range(input.begin(), input.end());
	} catch (Span::SpanOverflow const &e)
	{
		std::cerr << "[Caught Error] " << e.what() << std::endl;
	}
	std::cout << "Span from vector: " << span << std::endl;
	// Copy span
	Span span2(span);
	std::cout << "Span from Span: " << span << std::endl;
	std::cout << std::endl;
}

