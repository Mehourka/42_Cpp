#pragma once
#include "Common.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
	const static int	_SIZE = 8;
	int					m_write_index;
	Contact				m_contact_list[_SIZE];


private:
	void		moveIndex();
	Contact		*getNextContactPtr();
	void		printTableHeader() const;
	void		printTableRow(int idx, Contact contact) const;
	void		printCell(string str) const;
	string		getUserInput(string prompt) const;
	void		printContactTable() const;
	void		printTableHLine() const;
	bool		isInt(string snum) const;
	void		addContact();
	void		searchContact() const;
	void		check_cin() const;

public:
	PhoneBook();
	void	run();
};
