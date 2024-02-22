#include "PhoneBook.hpp"

// Constructor
PhoneBook::PhoneBook()
{
	m_write_index = 0;
}

// Utils
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

void	PhoneBook::moveIndex() 
{
	m_write_index++;
	m_write_index %= 8;
}

void PhoneBook::check_cin() const
{
	if (std::cin.fail() || std::cin.eof())
	{
		std::cout << "\n[Invalid Input]\n";
		std::cout << "Exiting Phonebook ...\n" << std::endl;
		exit(0);
	}
}


// Printing
void PhoneBook::printCell(std::string str) const
{
	(void)str;
	if (str.size() > 10)
	{
		str = str.substr(0, 9) + ".";
	}
	cout << std::setfill(' ') << std::left;
	cout << std::setw(10) << str;
}

void PhoneBook::printTableRow(int idx, Contact contact) const
{
	std::stringstream id;

	id << idx;
	printCell(id.str());
	cout << " | ";
	printCell(contact.getFirstName());
	cout << " | ";
	printCell(contact.getLastName());
	cout << " | ";
	printCell(contact.getNickname());
	cout << " |" << std::endl;
}

void PhoneBook::printTableHLine() const
{
	int underline_size = 10 * 4 + 12;
	cout << std::setfill('-') << std::setw(underline_size) << "\n" << std::endl;	
}

void PhoneBook::printTableHeader() const
{
	printTableHLine();
	printCell("ID");
	cout << " | ";
	printCell("First Name");
	cout << " | ";
	printCell("Last Name");
	cout << " | ";
	printCell("Nickname");
	cout << " |";
	printTableHLine();
	
}

void PhoneBook::printContactTable() const
{
	Contact	contact;

	printTableHeader();
	for (int i = 0; i < PhoneBook::_SIZE; i++)
	{
		contact = m_contact_list[i];
		
		if(contact.isValid())
			printTableRow(i, contact);
	}
	printTableHLine();
}


// Main usage functions
void PhoneBook::addContact(void)
{
	Contact *contact = getNextContactPtr();

	cout << "\n\nCreating new contact:\n";

	contact->setFirstName(getUserInput("First Name: "));
	contact->setLastName(getUserInput("Last Name: "));
	contact->setNickname(getUserInput("NickName: "));
	contact->setNumber(getUserInput("Phone Number: "));
	contact->setSecret(getUserInput("Darkest Secret: "));

	if (contact->isValid())
	{
		std::cout << "\nContact added successfully!\n\n" << std::endl;
		moveIndex();
	}
	else
	{
		std::cout << "\nCan't add contact!\n\n" << std::endl;
	}
}

bool PhoneBook::isInt(string s) const 
{
	string::iterator it = s.begin();

	if (s.size() > 10)
		return false;

	while (it != s.end() && std::isdigit(*it)) 
		it++;
	return (!s.empty() && it == s.end());
}

void PhoneBook::searchContact() const
{
	string idx_string = "";
	int idx;
	Contact contact;

	while (true)
	{
		printContactTable();

		idx = -1;
		idx_string = getUserInput("\n\nEnter user ID or 'exit': ");
		if (idx_string == "exit")
		{
			cout << "Return to main menu ... \n" << std::endl;
			return ;
		}

		if (isInt(idx_string)) idx = std::stoi(idx_string);

		if (idx >= 0 && idx < PhoneBook::_SIZE)
		{
			contact = m_contact_list[idx];
			if (contact.isValid())
			{
				contact.printInfo();
				return ;
			}
		}
		cout << "Invalid input. Try agin\n" << std::endl;
	}
}

void PhoneBook::run()
{
	
	std::string command;

	while (true)
	{
		std::cout << "\nEnter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		check_cin();
		if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook ...\n" << std::endl;
			break;
		}
		if (command == "ADD")
		{
			this->addContact();
		}
		else if (command == "SEARCH")
		{
			this->searchContact();
		}
		else
		{
			std::cout << "invalid command, Please try again.\n" << std::endl;
		}
	}
}
