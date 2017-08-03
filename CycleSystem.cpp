#include "CycleSystem.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <msclr\marshal_cppstd.h>

#include <sstream>

#pragma comment(lib, "User32.lib")

using namespace System;
using namespace System::IO;

string response;

CycleSystem::CycleSystem()
{
	m_input = new Input();
	ReadFiles();
}

CycleSystem::~CycleSystem()
{
	m_tourVector.clear();
	m_customerVector.clear();
	m_bookingVector.clear();

}

void CycleSystem::ReadFiles()
{
	ReadCustomerFiles();
	ReadTourFiles();
	ReadBookingFiles();
}

void CycleSystem::ReadCustomerFiles()
{
	string input;
	int numCustomers = 1;
	string Items;

	try
	{
		String^ file = "assets/customerList.txt";
		StreamReader^ sr = gcnew StreamReader(file);
		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			Customer* newCustomer = new Customer(0, "", "", "", false);

			input = msclr::interop::marshal_as<std::string>(line);

			istringstream ss(input);

			while (getline(ss, Items, ','))
			{
				//cout << Items << '\n'; for testing
				m_customerStringVector.push_back(Items);
			}

			// set values and push to vector
			newCustomer->setID(m_customerStringVector[m_customerStringVector.size() - 5]);
			newCustomer->setFirstName(m_customerStringVector[m_customerStringVector.size() - 4]);
			newCustomer->setSurname(m_customerStringVector[m_customerStringVector.size() - 3]);
			newCustomer->setPassport(m_customerStringVector[m_customerStringVector.size() - 2]);
			newCustomer->setEmail(m_customerStringVector[m_customerStringVector.size() - 1]);

			m_customerVector.push_back(newCustomer);

			numCustomers++;
		}
		sr->Close();
	}
	catch (Exception^ e)
	{
		Console::WriteLine("The file could not be read:");
		Console::WriteLine(e->Message);
	}
}

void CycleSystem::ReadTourFiles()
{
	string input;
	int numTours = 1;
	int numItems = 0;
	string Items;

	try
	{
		String^ file = "assets/tourList.txt";
		StreamReader^ sr = gcnew StreamReader(file);
		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			Tour* newTour = new Tour(0, "", "", "", "", "", "", "", false, 0, 0.0f);

			input = msclr::interop::marshal_as<std::string>(line);

			istringstream ss(input);

			while (getline(ss, Items, ','))
			{
				//cout << Items << '\n';
				m_tourStringVector.push_back(Items);
			}

			// set values and push to vector
			newTour->setID(m_tourStringVector[m_tourStringVector.size() - 11]);
			newTour->setStartL(m_tourStringVector[m_tourStringVector.size() - 10]);
			newTour->setEndL(m_tourStringVector[m_tourStringVector.size() - 9]);
			newTour->setStartH(m_tourStringVector[m_tourStringVector.size() - 8]);
			newTour->setEndH(m_tourStringVector[m_tourStringVector.size() - 7]);
			newTour->setNotesFile(m_tourStringVector[m_tourStringVector.size() - 6]);
			newTour->setGPSFile(m_tourStringVector[m_tourStringVector.size() - 5]);
			newTour->setLeader(m_tourStringVector[m_tourStringVector.size() - 4]);
			newTour->setPassportReq(m_tourStringVector[m_tourStringVector.size() - 3]);
			newTour->setAvailability(m_tourStringVector[m_tourStringVector.size() - 2]);
			newTour->setCost(m_tourStringVector[m_tourStringVector.size() -1]);

			m_tourVector.push_back(newTour);

			numTours++;
		}
		sr->Close();
	}
	catch (Exception^ e)
	{
		Console::WriteLine("The file could not be read:");
		Console::WriteLine(e->Message);
	}
}

void CycleSystem::ReadBookingFiles()
{
	string input;
	int numBookings = 1;
	string Items;

	try
	{
		String^ file = "assets/bookingList.txt";
		StreamReader^ sr = gcnew StreamReader(file);
		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			Booking* newBooking = new Booking(0, 0, 0, "");

			input = msclr::interop::marshal_as<std::string>(line);

			istringstream ss(input);

			while (getline(ss, Items, ','))
			{
				//cout << Items << '\n';
				m_bookingStringVector.push_back(Items);
			}

			// set values and push to vector
			newBooking->setID(m_bookingStringVector[m_bookingStringVector.size() - 4]);
			newBooking->setCustID(m_bookingStringVector[m_bookingStringVector.size() - 3]);
			newBooking->setTourID(m_bookingStringVector[m_bookingStringVector.size() - 2]);
			newBooking->setFeedback(m_bookingStringVector[m_bookingStringVector.size() - 1]);

			m_bookingVector.push_back(newBooking);

			numBookings++;
		}
		sr->Close();
	}
	catch (Exception^ e)
	{
		Console::WriteLine("The file could not be read:");
		Console::WriteLine(e->Message);
	}
}

void CycleSystem::SystemStartMessage()
{
	system("cls");
	cout << "Press: " << endl;
	cout << "C for Customer enquiries" << endl;
	cout << "T for Tour enquiries" << endl;
	cout << "B for Booking enquiries" << endl;
	cout << "L for Legal enquiries" << endl;
	cout << "I for Information enquiries" << endl;
	cout << "Q to Quit program" << endl;

	CustomerTourBookingCheck();	
}

void CycleSystem::CustomerTourBookingCheck()
{
	if (m_input)
	{
		// check keys pressed to update variables

		while (!m_input->KeyIsPressed(KEY_ESCAPE))
		{
			m_input->Update();

			cin >> response;
			system("cls");
			if (response == "c" || response == "C")
			{
				cout << "(A)dd, (R)emove, (V)iew, or (U)pdate customer info, or (G)o back?" << endl;
				cin >> response;

				if (response == "a" || response == "A")
					AddNewCustomer();
				else if (response == "r" || response == "R")
					RemoveCustomerInfoMessage(); // might not need this, but I'll include it anyway
				else if (response == "v" || response == "V")
					ViewCustomerInfo();
				else if (response == "u" || response == "U")
					UpdateCustomerInfo();
				else if (response == "g" || response == "G")
					SystemStartMessage();
				else
				{
					cout << "System didn't recognise input, press enter to return to start screen" << endl;
					SystemStartMessage();
				}
			}
			if (response == "t" || response == "T")
			{
				cout << "(A)dd, (R)emove, (V)iew, or (U)pdate tour info, or (G)o back?" << endl;
				cin >> response;

				if (response == "a" || response == "A")
					AddNewTour();
				else if (response == "r" || response == "R")
					RemoveTourMessage();
				else if (response == "v" || response == "V")
					ViewTour();
				else if (response == "u" || response == "U")
					UpdateTourInfo();
				else if (response == "g" || response == "G")
					SystemStartMessage();
				else
				{
					cout << "System didn't recognise input, press enter to return to start screen" << endl;
					SystemStartMessage();
				}
			}
			if (response == "b" || response == "B")
			{
				cout << "(A)dd, (R)emove, or (V)iew bookings, add (F)eedback, or (G)o back?" << endl;
				cin >> response;

				if (response == "a" || response == "A")
					AddBooking();
				else if (response == "r" || response == "R")
					CancelBookingMessage();
				else if (response == "v" || response == "V")
					ViewBooking();
				else if (response == "g" || response == "G")
					SystemStartMessage();
				else if (response == "f" || response == "F")
					AddFeedback();
				else
				{
					cout << "System didn't recognise input, press enter to return to start screen" << endl;
					SystemStartMessage();
				}
			}
			if (response == "l" || response == "L")
			{
				cout << "Legal Requirements to Book tour go here..." << endl;
				cout << "" << endl;
				cout << "Press G to go back" << endl;
				cin >> response;

				if (response == "g" || response == "G")
					SystemStartMessage();
				else
				{
					cout << "System didn't recognise input, press enter to return to start screen" << endl;
					SystemStartMessage();
				}
			}
			if (response == "i" || response == "I")
			{
				cout << "How to book a tour..." << endl;
				cout << "Information could be read from a text file" << endl;
				cout << "This can be updated with other types of information by adding an input/menu system similar to the start screen" << endl;
				cout << "" << endl;
				cout << "Press G to go back" << endl;
				cin >> response;

				if (response == "g" || response == "G")
					SystemStartMessage();
				else
				{
					cout << "System didn't recognise input, press enter to return to start screen" << endl;
					SystemStartMessage();
				}
			}
			if (response == "q" || response == "Q")
			{
				return;
			}
			Update();
		}
	}
	
}

void CycleSystem::Update(void)
{
	SystemStartMessage();
}

void CycleSystem::AddNewTour()
{
	// seperate these like I did with Remove?
	int tourNo = m_tourVector.size();
	String^ tourListFile = "assets/tourList.txt";

	int TourID = m_tourVector.size(); // new line, new ID
	string startL, endL, startH, endH, notes, gps, leaderName;
	bool passportReq;
	int availability;
	float cost;

	getline(cin, startL);					// was skipping the first input, so added this to try fixing it, not sure why it happened though

	cout << "Enter Start Location: ";
	getline(cin, startL);
	cout << "Enter End Location: ";
	getline(cin, endL);
	cout << "Enter Start Hotel: ";
	getline(cin, startH);
	cout << "Enter End Hotel: ";
	getline(cin, endH);
	cout << "Enter Notes file location: ";
	getline(cin, notes);
	cout << "Enter GPS file location: ";
	getline(cin, gps);
	cout << "Enter Leader name: ";
	getline(cin, leaderName);
	cout << "Is passport required?: ";
	cin >> passportReq;
	cout << "Number of spaces: ";
	cin >> availability;
	cout << "Cost of Tour: ";
	cin >> cost;

	System::String^ startL2 = msclr::interop::marshal_as<System::String^>(startL);
	System::String^ endL2 = msclr::interop::marshal_as<System::String^>(endL);
	System::String^ startH2 = msclr::interop::marshal_as<System::String^>(startH);
	System::String^ endH2 = msclr::interop::marshal_as<System::String^>(endH);
	System::String^ notes2 = msclr::interop::marshal_as<System::String^>(notes);
	System::String^ gps2 = msclr::interop::marshal_as<System::String^>(gps);
	System::String^ leaderName2 = msclr::interop::marshal_as<System::String^>(leaderName);

	Tour* newTour = new Tour(TourID, startL, endL, startH, endH, notes, gps, leaderName, passportReq, availability, cost);
	
	m_tourVector.push_back(newTour);

	String^ newString = String::Concat(
		TourID, ", ",
		startL2->ToUpper(), ", ",
		endL2->ToUpper(), ", ",
		startH2->ToUpper(), ", ",
		endH2->ToUpper(), ", ",
		notes2, ", ",
		gps2, ", ",
		leaderName2->ToUpper(), ", ",
		passportReq, ", ",
		availability, ", ",
		cost);

	StreamWriter^ sw = gcnew StreamWriter(tourListFile, true);
	sw->WriteLine(newString);
	sw->Close();

	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> response;
	if (response == "g" || response == "G")
		SystemStartMessage();
}

void CycleSystem::AddNewCustomer()
{
	int customerNo = m_customerVector.size();
	String^ customerListFile = "assets/customerList.txt";
	
	int custID = m_customerVector.size(); // new line, new ID
	string firstName, surName;
	bool hasPassport;
	string email;

	getline(cin, firstName);					// was skipping the first input for some reason, so added this for now.
	cout << "Enter First Name: ";
	getline(cin, firstName);
	cout << "Enter Surname: ";
	getline(cin, surName);
	cout << "Does the customer have a passport?: ";
	cin >> hasPassport;
	cout << "Customer email: ";
	cin >> email;

	System::String^ firstName2 = msclr::interop::marshal_as<System::String^>(firstName);
	System::String^ surName2 = msclr::interop::marshal_as<System::String^>(surName);
	System::String^ email2 = msclr::interop::marshal_as<System::String^>(email);
	
	Customer* newCustomer = new Customer(custID, firstName, surName, email, hasPassport);

	m_customerVector.push_back(newCustomer);

	String^ newString = String::Concat(
		custID, ", ",
		firstName2->ToUpper(), ", ",
		surName2->ToUpper(), ", ",
		hasPassport, ", ",
		email2->ToUpper());

	StreamWriter^ sw = gcnew StreamWriter(customerListFile, true);
	sw->WriteLine(newString);
	sw->Close();

	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> response;
	if (response == "g" || response == "G")
		SystemStartMessage();
}

void CycleSystem::AddBooking()
{
	int bookingNo = m_bookingVector.size();
	String^ bookingListFile = "assets/bookingList.txt";
	
	int bookingID = m_bookingVector.size(); // new line, new ID
	int custID = 0;
	int tourID = 0;
	string feedback = "";
	
	cout << "Enter Customer ID: ";
	cin >> custID;
	cout << "Enter Tour ID: ";
	cin >> tourID;
	// no feedback input as the customer hasn't been yet
	
	Booking* newBooking = new Booking(bookingID, custID, tourID, feedback);

	m_bookingVector.push_back(newBooking);

	String^ newString = String::Concat(
		bookingID, ", ",
		custID, ", ",
		tourID, ", ",
		feedback);

	StreamWriter^ sw = gcnew StreamWriter(bookingListFile, true);
	sw->WriteLine(newString);
	sw->Close();
	

	for (int i = 0; i < m_tourVector.size(); i++)
	{
		if (m_tourVector[i]->getID() == tourID)
		{
			string newAvailability = std::to_string(m_tourVector[i]->getAvailability() - 1); // need to convert to string for set function below

			m_tourVector[i]->setAvailability(newAvailability);
			UpdateTourInfo();
		}
	}

	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> response;
	if (response == "g" || response == "G")
		SystemStartMessage();
}

void CycleSystem::AddFeedback()
{
	int responseInt;
	string responseString;
	string feedback;

	cout << "Enter Booking ID: "; // maybe find customer id instead
	cin >> responseInt;
	//String^ response2 = msclr::interop::marshal_as<System::String^>(response);

	for (int i = 0; i < m_bookingVector.size(); i++)
	{
		if (m_bookingVector[i]->getBookingID() == responseInt)
		{
			cout << "Enter Feedback: ";
			getline(cin, feedback);
			getline(cin, feedback);
			m_bookingVector[i]->setFeedback(feedback);
			UpdateBooking(); // update booking text file
		}
	}
	
	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> responseString;
	if (responseString == "g" || responseString == "G")
		SystemStartMessage();
}

void CycleSystem::ViewTour()
{
	string response;

	cout << "Enter Tour start location: ";
	cin >> response;
	String^ response2 = msclr::interop::marshal_as<System::String^>(response);

	try
	{
		String^ tourListFile = "assets/tourList.txt";
		StreamReader^ sr = gcnew StreamReader(tourListFile);
		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			if (line->Contains(response2->ToUpper()))
			{
				Console::WriteLine(line);
			}
		}
		sr->Close();
	}
	catch (Exception^ e)
	{
		Console::WriteLine("The file could not be read:");
		Console::WriteLine(e->Message);
	}

	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> response;
	if (response == "g" || response == "G")
		SystemStartMessage();
}

void CycleSystem::ViewCustomerInfo()
{
	string response;

	cout << "Enter Customer Surname: ";
	cin >> response;
	String^ response2 = msclr::interop::marshal_as<System::String^>(response);

	try
	{
		String^ customerListFile = "assets/customerList.txt";
		StreamReader^ sr = gcnew StreamReader(customerListFile);
		String^ line;

		while ((line = sr->ReadLine()) != nullptr)
		{
			if (line->Contains(response2->ToUpper()))
			{
				Console::WriteLine(line);
			}
		}
		sr->Close();
	}
	catch (Exception^ e)
	{
		Console::WriteLine("The file could not be read:");
		Console::WriteLine(e->Message);
	}

	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> response;
	if (response == "g" || response == "G")
		SystemStartMessage();
}

void CycleSystem::ViewBooking()
{
	int response;
	string response2;

	cout << "Enter Customer ID: ";
	cin >> response;
	
	for (int i = 0; i < m_bookingVector.size(); i++)
	{
		if (m_bookingVector[i]->getCustID() == response)
		{
			// if there is no entry, it will display nothing
			m_bookingVector[i]->displayBooking();
		}
	}

	cout << "" << endl;
	cout << "Completed, press g to go back..." << endl;
	cin >> response2;
	if (response2 == "g" || response2 == "G")
		SystemStartMessage();
}

void CycleSystem::UpdateCustomerInfo()
{
	// Removes text file, and rewrites based on m_customerVector.
	// This means that the vector needs to change before this function gets called
	remove("assets/customerList.txt");

	String^ customerListFile = "assets/customerList.txt";
	StreamWriter^ sw = gcnew StreamWriter(customerListFile);

	// go through vector and rewrite file
	for (int i = 0; i < m_customerVector.size(); i++)
	{
		String^ firstName = msclr::interop::marshal_as<System::String^>(m_customerVector[i]->getFirstName());
		String^ surname = msclr::interop::marshal_as<System::String^>(m_customerVector[i]->getSurname());
		String^ email = msclr::interop::marshal_as<System::String^>(m_customerVector[i]->getEmail());

		String^ newString = String::Concat(
			m_customerVector[i]->getID(), ", ",
			firstName->ToUpper(), ", ",
			surname->ToUpper(), ", ",
			email->ToUpper(), ", ",
			m_customerVector[i]->getPassport());

		sw->WriteLine(newString);
	}
	sw->Close();
}

void CycleSystem::UpdateTourInfo()
{
	remove("assets/tourList.txt");

	String^ tourListFile = "assets/tourList.txt";
	StreamWriter^ sw = gcnew StreamWriter(tourListFile); // set to false/leave 2nd parameter blank to overwrite file (or create it if it doesn't exist)

	// go through vector and rewrite file
	for (int i = 0; i < m_tourVector.size(); i++)
	{
		String^ startL2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getStartL());
		String^ endL2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getEndL());
		String^ startH2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getStartH());
		String^ endH2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getEndH());
		String^ notes2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getNotesFile());
		String^ gps2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getGPSFile());
		String^ leaderName2 = msclr::interop::marshal_as<System::String^>(m_tourVector[i]->getLeader());

		String^ newString = String::Concat(
			m_tourVector[i]->getID(), ", ",
			startL2->ToUpper(), ", ",
			endL2->ToUpper(), ", ",
			startH2->ToUpper(), ", ",
			endH2->ToUpper(), ", ",
			notes2, ", ",
			gps2, ", ",
			leaderName2->ToUpper(), ", ",
			m_tourVector[i]->getPassportReq(), ", ",
			m_tourVector[i]->getAvailability(), ", ",
			m_tourVector[i]->getCost());

		sw->WriteLine(newString);
	}
	sw->Close();

}

// messages asking to remove entries
// This requires user to know the ID first. Could possibly rewrite it, but there isn't much need to.
void CycleSystem::RemoveTourMessage()
{
	// Ask for an input for which to remove
	// Remove old text file
	// Create text file again, same name, with new info from vector - Probably not the most efficient, but it works
	
	int responseInt = 0;
	string responseString;

	cout << "Enter the Tour ID to remove: ";
	cin >> responseInt;
	
	for (int i = 0; i < m_tourVector.size(); i++)
	{
		if (m_tourVector[i]->getID() == responseInt)
		{
			// erase entry in Vector
			m_tourVector.erase(m_tourVector.begin() + responseInt);
		}
	}

	UpdateTourInfo();

	cout << "" << endl;
	cout << "Completed Press g to go back..." << endl;
	cin >> responseString;
	if (responseString == "g" || responseString == "G")
		SystemStartMessage();
}

void CycleSystem::RemoveCustomerInfoMessage()
{
	int responseInt = 0;
	string responseString;

	cout << "Enter the Customer ID to remove: ";
	cin >> responseInt;

	for (int i = 0; i < m_tourVector.size(); i++)
	{
		if (m_customerVector[i]->getID() == responseInt)
		{
			m_customerVector.erase(m_customerVector.begin() + responseInt);
		}
	}

	UpdateCustomerInfo();

	cout << "" << endl;
	cout << "Completed Press g to go back..." << endl;
	cin >> responseString;
	if (responseString == "g" || responseString == "G")
		SystemStartMessage();
}

void CycleSystem::CancelBookingMessage()
{
	int responseInt = 0;
	string responseString;

	// COuld probably search for the CUstomer ID here, they probably aren't booked for more than 1 at a time anyway
	cout << "Enter the Booking ID to remove: ";
	cin >> responseInt;

	for (int i = 0; i < m_bookingVector.size(); i++)
	{
		if (m_bookingVector[i]->getBookingID() == responseInt)
		{
			m_bookingVector.erase(m_bookingVector.begin() + responseInt);
		}
	}

	UpdateBooking();

	cout << "" << endl;
	cout << "Completed Press g to go back..." << endl;
	cin >> responseString;
	if (responseString == "g" || responseString == "G")
		SystemStartMessage();
}

void CycleSystem::UpdateBooking()
{
	remove("assets/bookingList.txt");

	String^ bookingListFile = "assets/bookingList.txt";
	StreamWriter^ sw = gcnew StreamWriter(bookingListFile);

	// go through vector and rewrite file
	for (int i = 0; i < m_bookingVector.size(); i++)
	{
		String^ feedback = msclr::interop::marshal_as<System::String^>(m_bookingVector[i]->getFeedback());

		String^ newString = String::Concat(
			m_bookingVector[i]->getBookingID(), ", ",
			m_bookingVector[i]->getCustID(), ", ",
			m_bookingVector[i]->getTourID(), ", ",
			feedback);

		sw->WriteLine(newString);
	}
	sw->Close();
}