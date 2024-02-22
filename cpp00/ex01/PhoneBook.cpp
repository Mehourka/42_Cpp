#include "PhoneBook.hpp"

std::string PhoneBook::GetUserInput(std::string prompt) const
{
	std::string user_input = "";
	while (user_input.empty())
	{
		std::cout << prompt;
		std::getline(std::cin, user_input);
		if (user_input.empty())
			std::cout << "Can't have an empty field. please try again." << std::endl;
	}
	return (user_input);
}

Contact *PhoneBook::GetNextContactPtr()
{
	return &m_contact_list[m_write_index];
}

void PhoneBook::AddContact(void)
{
	Contact *contact = GetNextContactPtr();

	// Ask user for each entry
	contact->setFirstName(GetUserInput("First Name: "));
	contact->setLastName(GetUserInput("Last Name: "));
	contact->setNickname(GetUserInput("NickName: "));
	contact->setNumber(GetUserInput("Phone Number: "));
	contact->setSecret(GetUserInput("Darkest Secret: "));

	contact->printRow();

	// Add new contact to m_contact_list[m_write_index]
	// increment the write index, loop on 8
}