#pragma once
#include "Common.hpp"

class Brain
{
public:
	Brain();
	virtual ~Brain();
	Brain(const Brain &);
	Brain & operator = (const Brain &);

	const static int capacity= 100;

private:
	std::string _ideas[Brain::capacity];

protected:
	static void copyIdeas(const Brain &src, Brain &dest);

public:
	void printIdeas() const;
	void addIdea(int idx, const std::string &idea);

};
