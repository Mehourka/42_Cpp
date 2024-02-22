#include "PhoneBook.hpp"

using std::cout;
using std::string;

void printHeader()
{
	std::cout << "\n\n\n\nThe PhoneBook :\n";
	std::cout << std::setfill('_') << std::setw(18) << "\n" << std::endl;
}


int main(void)
{
	PhoneBook phone_book;
	printHeader();

	phone_book.run();

	return (0);
}
