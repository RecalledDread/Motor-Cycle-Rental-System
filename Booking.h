#include <string>
#include <iostream>

using namespace std;

#pragma once

class Booking
{
public:
	Booking(int id, int customerId, int tourId, string feedback);
	~Booking();

	void setID(string id);
	void setCustID(string custID);
	void setTourID(string tourID);
	void setFeedback(string feedback);

	int		getBookingID();
	int		getCustID();
	int		getTourID();
	string	getFeedback();

	void displayBooking();

private:

	int		m_bookingInfoID;
	int		m_customerID;
	int		m_tourID;
	string	m_feedback;


};