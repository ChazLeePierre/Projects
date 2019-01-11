// Workshop 3: Classes and Privacy
// w3_in_lab.cpp
// Version 2.1
// June 1st 2018
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student #: 123206179
// Description
// This workshop demonstrates classes in C++ and 
// how member variables are defined privately, but 
// accessed through public member functions
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		                         Reason
// Chris        2018/01/23            allow longer names
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict {
	char familyNameStored[max_name_length] = "";
	char givenNameStored[max_name_length] = "";
	int sinStored = -1;
	
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		// set first/last name and sin number if sin is valid
		if (sin > min_sin && sin < max_sin) {
			strncpy(familyNameStored, familyName, max_name_length + 1);
			strncpy(givenNameStored, givenName, max_name_length + 1);
			sinStored = sin;
		}
		else {
			sinStored = -1;
			return;
		}
	}

	bool CRA_Account::isEmpty() const {
		return sinStored == -1 ? true : false;
	}

	void CRA_Account::display() const {
		if (!(isEmpty())) {
			cout << "Family Name: " << familyNameStored << endl
				<< "Given Name : " << givenNameStored << endl
				<< "CRA Account: " << sinStored << endl;
		}
		else {
			cout << "Account object is empty!" << endl;
		}
	}
}
