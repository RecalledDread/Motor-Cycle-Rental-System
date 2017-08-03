#include "Booking.h"


Booking::Booking(int id, int customerId, int tourId, string feedback)
{
	m_bookingInfoID = id;
	m_customerID = customerId;
	m_tourID = tourId;
	m_feedback = feedback;
}

Booking::~Booking()
{

}


void Booking::setID(string id)
{
	m_bookingInfoID = atoi(id.c_str());
}

void Booking::setCustID(string custID)
{
	m_customerID = atoi(custID.c_str());
}

void Booking::setTourID(string tourID)
{
	m_tourID = atoi(tourID.c_str());
}

void Booking::setFeedback(string feedback)
{
	m_feedback = feedback;
}

void Booking::displayBooking()
{
	cout << m_bookingInfoID; cout << ", ";
	cout << m_customerID; cout << ", ";
	cout << m_tourID; cout << ", ";
	cout << m_feedback << endl;
}


int Booking::getBookingID()
{
	return m_bookingInfoID;
}

int Booking::getCustID()
{
	return m_customerID;
}

int Booking::getTourID()
{
	return m_tourID;
}

string Booking::getFeedback()
{
	return m_feedback;
}
