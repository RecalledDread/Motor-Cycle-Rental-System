#include <string>

using namespace std;

#pragma once

class Tour
{
public:
	Tour(int id, string startlocale, string endlocale, string starthotel, string endhotel, string notes, string gpsfile, string leader, bool passportReq, int availablity, float cost);
	~Tour();

	void setID(string id);
	void setStartL(string startL);
	void setEndL(string endL);
	void setStartH(string startH);
	void setEndH(string endH);
	void setNotesFile(string notesFile);
	void setGPSFile(string gpsFile);
	void setLeader(string leader);
	void setPassportReq(string passportReq);
	void setAvailability(string availability);
	void setCost(string cost);

	int		getID();
	string	getStartL();
	string	getEndL();
	string	getStartH();
	string	getEndH();
	string	getNotesFile();
	string	getGPSFile();
	string	getLeader();
	bool	getPassportReq();
	int		getAvailability();
	float	getCost();

private:
	int		m_ID;
	string	m_startLocation;
	string	m_endLocation;
	string	m_startHotel;
	string	m_endHotel;
	string	m_routeNotes;			// filename/location
	string	m_gpsFile;				// filename/location
	string	m_leader;
	bool	m_passportReq;			// is passport required for this tour?
	int		m_tourAvailability;
	float	m_cost;


};