#pragma once
#include "Common.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	int		m_write_index;
	Contact	m_contact_list[8];
	void	MoveIndex() {m_write_index++;}

public:
	PhoneBook() {m_write_index = 0;}


	void AddContact();
	void SearchContact() const {};
	std::string GetUserInput(std::string prompt) const;
	Contact	*GetNextContactPtr();

};