/**********************************************************
// Workshop 4: Constructors
// Passenger.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// 
///////////////////////////////////////////////////////////
**********************************************************/

#include "Passenger.h"
#include <cstring>
#include <iostream>
#include <iomanip>

using namespace std;

namespace sict {

	Passenger::Passenger() { // constructor, set object to safe empty state
		namePassenger[0] = '\0';
		destPassenger[0] = '\0';
		yearOfDeparture = 0;
		monthOfDeparture = 0;
		dayOfDeparture = 0;
	}

	Passenger::Passenger(const char* name, const char* destination) { // if input data not empty, assign input data to object data
		if (name != nullptr && name[0] != '\0' && destination != nullptr && destination != '\0') {
			strcpy(namePassenger, name);
			strcpy(destPassenger, destination);
			yearOfDeparture = 2017;
			monthOfDeparture = 7;
			dayOfDeparture = 1;
		}
		else 
			*this = Passenger();
	}
	
	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day) { // if input data not empty, assign input data to object data
		if (name != nullptr && name[0] != '\0' && destination != nullptr && destination != '\0' && (year >= 2017 && year <= 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
			strcpy(namePassenger, name);
			strcpy(destPassenger, destination);
			yearOfDeparture = year;
			monthOfDeparture = month;
			dayOfDeparture = day;
		}
		else 
			*this = Passenger();
	}

	bool Passenger::isEmpty() const { // check if object data is empty
		return (( namePassenger[0] == '\0' || namePassenger == nullptr ) || ( destPassenger[0] == '\0' || destPassenger == nullptr ) || yearOfDeparture == 0 || monthOfDeparture == 0 || dayOfDeparture == 0) ?
			true :
			false; 
	}

	void Passenger::display() const { // display formatted data
		(isEmpty()) ? cout << "No passenger!" << endl :
		cout << namePassenger << " - " << destPassenger << " on " << yearOfDeparture << "/" << setfill('0') << setw(2) << monthOfDeparture << "/" << setfill('0') << setw(2) << dayOfDeparture << endl;
	}

	const char* Passenger::name() const { // return passenger name if not empty
		return (isEmpty()) ? "" : namePassenger;
	}

	bool Passenger::canTravelWith(const Passenger& passenger) const { // check if passenger can travel with each other based on if their flights match
		if (passenger.yearOfDeparture == yearOfDeparture)  
			if (passenger.monthOfDeparture == monthOfDeparture)  
				if (passenger.dayOfDeparture == dayOfDeparture)  
					if (strcmp(passenger.destPassenger, destPassenger) == 0)  
						return true;
		return false;
	}

}
