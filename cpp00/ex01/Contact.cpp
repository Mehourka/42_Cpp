#include "Contact.hpp"

void Contact::initContact(
	string first_name,
	string last_name,
	string nickname,
	string phone_number,
	string secret)
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
	cout << std::setfill(' ') << std::left;
	cout << std::setw(10) << str;
}

void Contact::printRow() const
{
	std::stringstream id;

	int test;

	test = std::stoi("-123");


	id << 1 << test;
	printCell(id.str());
	cout << " | ";
	printCell(getFirstName());
	cout << " | ";
	printCell(getLastName());
	cout << " | ";
	printCell(getNickname());
	cout << std::endl;
}

bool	Contact::isValid() const
{
	if (
		m_first_name.empty() ||
		m_last_name.empty() ||
		m_nickname.empty() ||
		m_phone_number.empty() ||
		m_secret.empty()
	)
		return false;
	return true;

}

void		Contact::setFirstName(string str)	
{
	m_first_name = str;
}

void		Contact::setLastName(string str)	
{
	m_last_name = str;
}

void		Contact::setNickname(string str)	
{
	m_nickname = str;
}

void		Contact::setNumber(string str)		
{
	m_phone_number = str;
}

void		Contact::setSecret(string str)		
{
	m_secret = str;
}

std::string	Contact::getFirstName()			const	
{
	return m_first_name;
}

std::string	Contact::getLastName()			const	
{
	return m_last_name;
}

std::string	Contact::getNickname()			const	
{
	return m_nickname;
}

std::string	Contact::getNumber()				const	
{
	return m_phone_number;
}

std::string	Contact::getSecret()				const	
{
	return m_secret;
}


