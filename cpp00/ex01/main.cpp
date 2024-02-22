#include "PhoneBook.hpp"

// Class contacte

// Class Phone book
// - tableau de 8 contatctes max
// - on overflow, replace oldest contact
// - No dynamic allocation

int main(void)
{
	std::string command;

	PhoneBook phone_book;

	std::cout << "The PhoneBook :\n";
	std::cout << std::setfill('_') << std::setw(18) << "\n\n" << std::endl;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT")
		{
			std::cout << "Deleting Phonebook ...\n" << std::endl;
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
		else if (std::cin.fail()) 
		{
			exit(1);
		}
		else
		{
			std::cout << "Valid commands: ADD, SEARCH, EXIT. Please try again.\n\n" << std::endl;
		}
	}
	
	// Contact new_guy;

	// new_guy.printRow();
	return (0);
}
