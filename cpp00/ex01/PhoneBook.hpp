#pragma once
#include "Common.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	int		m_write_index;
	Contact	m_contact_list[8];
	void	moveIndex();

public:
	PhoneBook() {m_write_index = 0;}


	void addContact();
	void searchContact() const {};
	std::string getUserInput(std::string prompt) const;
	Contact	*getNextContactPtr();

};
