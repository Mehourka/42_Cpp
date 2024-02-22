#pragma once
#include "Common.hpp"

class Contact
{
private:
	string m_first_name;
	string m_last_name;
	string m_nickname;
	string m_phone_number;
	string m_secret;

public:
	Contact() {};

	void		initContact(
		string first_name,
		string last_name,
		string nickname,
		string phone_number,
		string secret
	);

	void		setFirstName(string str);
	void		setLastName(string str);
	void		setNickname(string str);
	void		setNumber(string str);
	void		setSecret(string str);
	string		getFirstName()	const;
	string		getLastName()	const;
	string		getNickname()	const;
	string		getNumber()		const;
	string		getSecret()		const;
	bool		isValid()		const;
	void 		printRow() const;

};
