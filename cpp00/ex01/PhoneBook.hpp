#pragma once
#include "Common.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	const static int	_SIZE = 8;
	int			m_write_index;
	Contact		m_contact_list[_SIZE];

private:
	void		moveIndex();

public:
	PhoneBook() {m_write_index = 0;}
	void	addContact();
	void	searchContact() const {};
	string	getUserInput(std::string prompt) const;
	Contact	*getNextContactPtr();
	void	printContactTable() const;
};
