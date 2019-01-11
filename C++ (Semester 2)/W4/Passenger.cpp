/**********************************************************
// Workshop 3: Classes and Privacy
// Passenger.cpp
// Name: Jihyun Yoon
// email: jyoon31@myseneca.ca
// Student#: 124558172
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Jihyun        2018/02/13                       file made
///////////////////////////////////////////////////////////
**********************************************************/

// TODO: add your headers here
#include "Passenger.h"
#include <cstring>
#include <iostream>

using namespace std;

namespace sict {

	Passenger::Passenger() {
		namePassenger[0] = '\0';
		destPassenger[0] = '\0';
	}

	Passenger::Passenger(const char* name, const char* destination) {
		if (name != nullptr && name[0] != '\0' && destination != nullptr && destination != '\0') {
			strcpy(namePassenger, name);
			strcpy(destPassenger, destination);
		}
		else 
			*this = Passenger();
	}
	
	bool Passenger::isEmpty() const {
		return (( namePassenger[0] == '\0') || ( destPassenger[0] == '\0')) ?
			true :
			false; 
	}

	void Passenger::display() const {
		(isEmpty()) ? cout << "No passenger!" << endl :
		cout << namePassenger << " - " << destPassenger << endl;
	}
}
