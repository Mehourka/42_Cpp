#pragma once
#include "Common.hpp"

class Contact
{
private:
	std::string m_first_name;
	std::string m_last_name;
	std::string m_nickname;
	std::string m_phone_number;
	std::string m_secret;

public:
	Contact() {};

	void		initContact(
		std::string first_name,
		std::string last_name,
		std::string nickname,
		std::string phone_number,
		std::string secret
	);

	void		setFirstName(std::string str)	{m_first_name = str;}
	void		setLastName(std::string str)	{m_last_name = str;}
	void		setNickname(std::string str)	{m_nickname = str;}
	void		setNumber(std::string str)		{m_phone_number = str;}
	void		setSecret(std::string str)		{m_secret = str;}
	std::string	getFirstName()			const	{return m_first_name;}
	std::string	getLastName()			const	{return m_last_name;}
	std::string	getNickname()			const	{return m_nickname;}
	std::string	getNumber()				const	{return m_phone_number;}
	std::string	getSecret()				const	{return m_secret;}
	void 		printRow() const;

};