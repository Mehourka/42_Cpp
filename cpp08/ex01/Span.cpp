#include "Span.hpp"
#include <limits>

int abs(int a)
{
	return a >= 0 ? a : -a;
}

// ======== Canonical Form ========
Span::Span(Span const &other) {
	*this = other;
}

Span& Span::operator= (Span const &other) {
	_max_size = other._max_size;
	insert_range(other._array.begin(), other._array.end());
	return *this;
}

Span::Span(int N){
	if (N < 0)
		throw(std::exception());
	_max_size = static_cast<size_t>(N);
}

Span::~Span() {

}


// ======== Mandatory functions ========
void Span::addNumber(int n) {
	_check_if_full();
	_array.push_back(n);
}


int	Span::shortestSpan() const {
	Span sorted_cpy(*this);

	if (_array.size() < 2)
		return 0;

	std::sort(sorted_cpy._array.begin(), sorted_cpy._array.end());
	int dist = std::numeric_limits<int>::max();
	int min_span = dist;
	for (size_t i = 0; i < _array.size() - 1; i++)
	{
		dist = abs( abs(sorted_cpy._array[i + 1]) - abs(sorted_cpy._array[i]));
		min_span = min_span < dist ? min_span : dist;
	}
	return min_span;
}

int		Span::longestSpan() const {
	if (_array.size() < 2)
		return 0;

	int min = _array[0];
	int max = _array[0];
	for (size_t i = 0; i < _array.size(); i++)
	{
		min = min < _array[i] ? min : _array[i];
		max = max > _array[i] ? max : _array[i];
	}
	return max - min; 
}

// ======== Utility functions ========
size_t Span::size() const {
	return _array.size();
}

int Span::get(size_t i) const {
	return _array[i];
}

void Span::_check_if_full() const
{
	if (_array.size() == _max_size)
		throw(Span::SpanOverflow());
}

// ======== Error ========
char const *Span::SpanOverflow::what() const throw()
{
	return "Span is at max capacity";
}

std::ostream& operator<<(std::ostream &out, Span const &span)
{
	out << "[";
	for(size_t i = 0; i < span.size(); i++) {
		out << span.get(i) << ", ";
	}
	out << " ]" << std::endl;
	return out;
}
