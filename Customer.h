#include <string>

using namespace std;

#pragma once

class Customer
{
public:
	Customer(int id, string firstName, string surname, string email, bool hasPassport);
	~Customer();

	void setID(string id);
	void setFirstName(string firstname);
	void setSurname(string surname);
	void setEmail(string email);
	void setPassport(string hasPassport);

	int		getID();
	string	getFirstName();
	string	getSurname();
	string	getEmail();
	bool	getPassport();

private:
	int		m_customerID;
	string	m_firstName;
	string	m_surname;
	string	m_email;
	bool	m_passport;


};