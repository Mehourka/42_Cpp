#include "Brain.hpp"

// -------------------- Canonical --------------------//

Brain::Brain()
{
	Log("Brain Default Constructor called");
}

Brain::~Brain()
{
	Log("Brain Default Destructore called");
}

Brain::Brain(const Brain &other)
{
	*this = other;
	Log("Brain Copy Constructor called");
}

Brain &Brain::operator=(const Brain &other)
{
	Brain::copyIdeas(other, *this);
	Log("Brain Assignation override called");
	return *this;
}

// -------------------- Utils -------------------- //
void Brain::copyIdeas(const Brain &src, Brain &dest)
{
	for (int i = 0; i < Brain::capacity; i++)
	{
		dest._ideas[i] = src._ideas[i];
	}
}

void Brain::printIdeas() const
{
	std::cout << "Ideas: " << std::endl;
	for (int i = 0; i < Brain::capacity; i++)
	{
		if (!_ideas[i].empty())
			std::cout << " - " << i << " " << _ideas[i] << std::endl;
	}
}

void Brain::addIdea(int idx, const std::string &idea)
{
	if (idx >= 0 && idx <= Brain::capacity)
	{
		_ideas[idx] = idea;
		return;
	}
	std::cout << "Invalid index. Possible values : [0 - "
			  << Brain::capacity << "]" << std::endl;
}