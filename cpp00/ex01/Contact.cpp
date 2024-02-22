#include "Contact.hpp"

void Contact::initContact(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone_number,
	std::string secret)
{
	setFirstName(first_name);
	setLastName(last_name);
	setNickname(nickname);
	setNumber(phone_number);
	setSecret(secret);
}

void printCell(std::string str)
{
	(void)str;
	if (str.size() > 10)
	{
		str = str.substr(0, 9) + ".";
	}
	std::cout << std::setfill('*') << std::left;
	std::cout << std::setw(10) << str;
}

void Contact::printRow() const
{
	std::stringstream id;

	id << 1;
	printCell(id.str());
	std::cout << " | ";
	printCell(getFirstName());
	std::cout << " | ";
	printCell(getLastName());
	std::cout << " | ";
	printCell(getNickname());
	std::cout << std::endl;
}