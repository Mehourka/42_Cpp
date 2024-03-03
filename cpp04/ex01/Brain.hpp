#pragma once
#include "Common.hpp"

class Brain
{
public:
	Brain();						 // Canonical
	virtual ~Brain();				 // Canonical
	Brain(const Brain &);			 // Canonical
	Brain &operator=(const Brain &); // Canonical

	const static int capacity = 100;

private:
	std::string _ideas[Brain::capacity];

protected:
	static void copyIdeas(const Brain &src, Brain &dest);

public:
	void printIdeas() const;
	void addIdea(int idx, const std::string &idea);
};
