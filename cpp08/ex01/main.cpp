#include <iostream>

#include "Span.hpp"

int main2()
{
	std::vector<int> input;

	for (int i = 0; i < 0; i++)
	{
		input.push_back(i * 3);
	}

	Span span(6);
	span.insert_range(input.begin(), input.end());
	std::cout << span << std::endl;

	Span span2(span);
	std::cout << span << std::endl;

	return 0;
}

int main()
{
	Span sp = Span(10);
	sp.addNumber(-100);
	sp.addNumber(100);
	sp.addNumber(20);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << sp << std::endl;
	return 0;
}
