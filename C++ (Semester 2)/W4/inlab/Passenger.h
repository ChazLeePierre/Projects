/**********************************************************
// Workshop 4: Constructors
// Passenger.h
// Name: Chaz Pierre
// email: cpierre4@myseneca.ca
// Student#: 123206179
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
///////////////////////////////////////////////////////////
**********************************************************/

#pragma once
#define SIZE 32

namespace sict {
	class Passenger {
		char namePassenger[SIZE];
		char destPassenger[SIZE];
	public:
		Passenger();
		Passenger(const char* name, const char* destination);
		bool isEmpty() const;
		void display() const;
	};
}
