#include "PhoneBook.hpp"

using std::cout;
using std::string;

void printHeader()
{
	std::cout << "The PhoneBook :\n";
	std::cout << std::setfill('_') << std::setw(18) << "\n\n" << std::endl;
}

void check_cin()
{
	if (std::cin.fail() || std::cin.eof())
	{
		std::cout << "\n[Invalid Input]\n";
		std::cout << "Exiting Phonebook ...\n" << std::endl;
		exit(0);
	}
}

void promptPhoneBook()
{
	PhoneBook phone_book;
	std::string command;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		check_cin();
		if (command == "EXIT")
		{
			std::cout << "Exiting PhoneBook ...\n" << std::endl;
			break;
		}
		if (command == "ADD")
		{
			phone_book.addContact();
		}
		else if (command == "SEARCH")
		{
			std::cout << "NotYetImplemented"<< std::endl;
		}
		else
		{
			std::cout << "Valid commands: ADD, SEARCH, EXIT. Please try again.\n\n" << std::endl;
		}
	}
}

int main(void)
{
	printHeader();
	promptPhoneBook();

	return (0);
}
