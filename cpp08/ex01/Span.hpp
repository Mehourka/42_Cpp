#pragma once

#include <vector>
#include <exception>
#include <iostream>

class Span {
public:
	class SpanOverflow: std::exception{
	public:
		char const *what() const throw();
	};

public:
	Span(int N);
	~Span();
	Span(Span const &other);
	Span& operator= (Span const &other);

	template <class InputIterator>
	void	insert_range(InputIterator first, InputIterator last);
	void	addNumber(int n);
	size_t	size() const;
	int		get(size_t i) const;
	int		shortestSpan() const;
	int		longestSpan() const;

private:

	void				_check_if_full() const;
	void				_print_span() const;
	size_t					_max_size;
	std::vector<int>	_array;
};


template <class InputIterator>
void Span::insert_range(InputIterator first, InputIterator last){
	InputIterator pos = first;
	while (pos != last) {
		addNumber(*pos);
		++pos;
	}
}

std::ostream& operator<<(std::ostream &out, Span const &span);
