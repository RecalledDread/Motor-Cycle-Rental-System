#pragma once

#include <string>
#include <vector>

#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>

#include "Tour.h"
#include "Customer.h"
#include "Booking.h"
#include "Input.h"

using namespace std;

class CycleSystem
{
private:
	vector<Tour*>		m_tourVector;
	vector<Customer*>	m_customerVector;
	vector<Booking*>	m_bookingVector;

	vector<string>	m_customerStringVector;
	vector<string>	m_tourStringVector;
	vector<string>	m_bookingStringVector;

	Input*				m_input;

public:
	CycleSystem();
	~CycleSystem();
	
	void SystemStartMessage();
	void CustomerTourBookingCheck();
	void Update();

	void AddNewTour();
	void AddNewCustomer();
	void AddBooking();			// add booking connection, remove availability from tour, may need to use name, then find id with that
	void AddFeedback();			// if customer calls to give feedback

	void ViewTour();			// may need to be tourStartlocation/Hotel
	void ViewCustomerInfo();	// may need to be ID
	void ViewBooking();			// may need to be ID, otherwise find Customer ID through ViewCustomerInfo, to the find Booking

	void UpdateCustomerInfo();
	void UpdateTourInfo();

	void RemoveTourMessage();
	void RemoveCustomerInfoMessage();
	void CancelBookingMessage();

	void RemoveCustomerInfo();
	void UpdateBooking();		// remove booking connection, add availability to tour

	void ReadFiles();			// read current files to push onto stacks
	void ReadCustomerFiles();			
	void ReadBookingFiles();			
	void ReadTourFiles();			

	bool m_running;
};