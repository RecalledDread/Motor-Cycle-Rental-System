#include "Customer.h"


Customer::Customer(int id, string firstName, string surname, string email, bool hasPassport)
{
	m_customerID  = id;
	m_firstName = firstName;
	m_surname = surname;
	m_email = email;
	m_passport = hasPassport;
}

Customer::~Customer()
{

}


void Customer::setID(string id)
{
	// convert string to integer value for reading files
	m_customerID = atoi(id.c_str());
}

void Customer::setFirstName(string fname)
{
	m_firstName = fname;
}

void Customer::setSurname(string sname)
{
	m_surname = sname;
}

void Customer::setEmail(string email)
{
	m_email = email;
}

void Customer::setPassport(string passport)
{
	m_passport = passport == "TRUE";
}

int	Customer::getID()
{
	return m_customerID;
}

string Customer::getFirstName()
{
	return m_firstName;
}

string Customer::getSurname()
{
	return m_surname;
}

string Customer::getEmail()
{
	return m_email;
}

bool Customer::getPassport()
{
	return m_passport;
}