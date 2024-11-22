#pragma once

#include <stack>


template<
	typename T,
	typename Container = std::deque<T>
> class MutantStack : public std::stack<T, Container> {
public:
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	iterator begin() {
		return this->c.begin(); 
	}

	const_iterator cbegin() {
		return this->c.cbegin();
	}

	const_iterator rcbegin() {
		return this->c.rcbegin();
	}

	iterator end() {
		return this->c.end(); 
	}

	const_iterator cend() {
		return this->c.cend(); 
	}

	const_iterator rcend() {
		return this->c.rcend(); 
	}
};
