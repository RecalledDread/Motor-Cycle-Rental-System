#include "Tour.h"


Tour::Tour(int id, string startlocale, string endlocale, string starthotel, string endhotel, string notes, string gpsfile, string leader, bool passportReq, int availablity, float cost)
{
	m_ID = id;
	m_startLocation = startlocale;
	m_endLocation = endlocale;
	m_startHotel = starthotel;
	m_endHotel = endhotel;
	m_routeNotes = notes;				// filename/location
	m_gpsFile = gpsfile;				// filename/location
	m_leader = leader;
	m_passportReq = passportReq;		// is passport required for this tour?
	m_tourAvailability = availablity;
	m_cost = cost;
}

Tour::~Tour()
{

}


void Tour::setID(string id)
{
	m_ID = atoi(id.c_str());
}

void Tour::setStartL(string startL)
{
	m_startLocation = startL;
}

void Tour::setEndL(string endL)
{
	m_endLocation = endL;
}

void Tour::setStartH(string startH)
{
	m_startHotel = startH;
}

void Tour::setEndH(string endH)
{
	m_endHotel = endH;
}

void Tour::setNotesFile(string notesFile)
{
	m_routeNotes = notesFile;
}

void Tour::setGPSFile(string gpsFile)
{
	m_gpsFile = gpsFile;
}

void Tour::setLeader(string leader)
{
	m_leader = leader;
}

void Tour::setPassportReq(string passportReq)
{
	m_passportReq = passportReq == "TRUE";
}

void Tour::setAvailability(string availability)
{
	m_tourAvailability = atoi(availability.c_str());
}

void Tour::setCost(string cost)
{
	//string::size_type sz = 0;
	m_cost = stof(cost);//.substr(sz));
}

int Tour::getID()
{
	return m_ID;
}

string Tour::getStartL()
{
	return m_startLocation;
}

string Tour::getEndL()
{
	return m_endLocation;
}

string Tour::getStartH()
{
	return m_startHotel;
}

string Tour::getEndH()
{
	return m_endHotel;
}

string Tour::getNotesFile()
{
	return m_routeNotes;
}

string Tour::getGPSFile()
{
	return m_gpsFile;
}

string Tour::getLeader()
{
	return m_leader;
}

bool Tour::getPassportReq()
{
	return m_passportReq;
}

int	Tour::getAvailability()
{
	return m_tourAvailability;
}

float Tour::getCost()
{
	return m_cost;
}
