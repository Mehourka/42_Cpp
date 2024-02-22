#include "PhoneBook.hpp"

string PhoneBook::getUserInput(std::string prompt) const
{
	string user_input = "";
	while (user_input.empty() && !std::cin.fail())
	{
		cout << prompt;
		std::getline(std::cin, user_input);
		check_cin();
		if (user_input.empty())
		{
			std::cout << "Can't have an empty field. please try again." << std::endl;
		}
	}
	return (user_input);
}

Contact *PhoneBook::getNextContactPtr()
{
	return &m_contact_list[m_write_index];
}

void PhoneBook::addContact(void)
{
	Contact *contact = getNextContactPtr();

	// Ask user for each entry
	contact->setFirstName(getUserInput("First Name: "));
	contact->setLastName(getUserInput("Last Name: "));
	contact->setNickname(getUserInput("NickName: "));
	contact->setNumber(getUserInput("Phone Number: "));
	contact->setSecret(getUserInput("Darkest Secret: "));

	// increment the write index, loop on 8
	if (contact->isValid())
	{
		std::cout << "Contact added successfully!\n\n" << std::endl;
		moveIndex();
	}
	else
	{
		std::cout << "Can't add contact! : " << std::endl;
	}
}

void	PhoneBook::moveIndex() 
{
	m_write_index++;
	m_write_index %= 9;
}

void PhoneBook::printContactTable() const
{
	Contact	contact;

	for (int i = 0; i < PhoneBook::_SIZE; i++)
	{
		contact = m_contact_list[i];

		if(contact.isValid())
			contact.printRow(i);
		
	}
}
