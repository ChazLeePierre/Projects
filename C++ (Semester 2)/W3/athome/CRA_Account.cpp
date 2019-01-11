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

#include <iostream>
#include <cstring>
#include <iomanip>
#include "CRA_Account.h"
using namespace std;

namespace sict {	
	bool CRA_Account::isSINvalid(int sin) const {
		int SIN[8] = {0};
    		int multiplesofTen = 1, sum = 0, alt = 0;
    		bool retval;
		// convert the SIN into seperate elements in an array
		for (int i = 8; i >= 0; i--) { 
			SIN[i] = sin / multiplesofTen % 10;
			multiplesofTen *= 10;
		}
		
		// check if SIN contains nine valid digits
		if (SIN[8] == 0)
			return false;
		         
		// check if SIN is valid using the Luhn algorithm
		for (int i = 0; i < 8; i++)
			(i % 2 == 0) ? 
				alt += SIN[i] :
				sum += ((SIN[i] * 2) / 10) + (SIN[i] * 2 % 10);
		
		retval = ((alt + sum + SIN[8]) % 10 == 0) ? true : false;
		return retval;	

	}
	void CRA_Account::set(int year, double balance) {
		if (isSINvalid(sin)) {
			if(countYears < max_yrs) {
				taxYear[countYears] = year;
				taxBalance[countYears] = balance;
				countYears++;
						
			}
		}
	}
	void CRA_Account::set(const char* familyName, const char* givenName, int sin) {
		// if SIN is not within range or string is empty, exit
		if (sin < min_sin || sin > max_sin || familyName[0] == '\0' || givenName[0] == '\0') { 
			CRA_Account::sin = -1;
			return;
		} else {
			// if valid SIN, store information
			if (isSINvalid(sin)) {
				strncpy(familyNameStored, familyName, max_name_length - 1);
				strncpy(givenNameStored, givenName, max_name_length - 1);
				CRA_Account::sin = sin;
				for (int i = 0; i < max_yrs; i++) {
					countYears = 0;
					taxYear[i] = 0;
					taxBalance[i] = 0;
				}
			}
		}
	}

	bool CRA_Account::isEmpty() const {
		// if SIN is empty, return true
		return sin == -1 ? true : false;
	}

	void CRA_Account::display() const {
		if (!(isEmpty())) {
			cout << "Family Name: " << familyNameStored << endl
				<< "Given Name : " << givenNameStored << endl
				<< "CRA Account: " << sin << endl;
			for (int i = 0; i < max_yrs; i++){
				if (taxBalance[i] > 2)
					(taxBalance[i] < 0) ?
					cout << "Year (" << taxYear[i] << ") balance owing: " << std::setprecision(2) << fixed << -taxBalance[i] << endl :
					cout << "Year (" << taxYear[i] << ") balance owing: " << std::setprecision(2) << fixed << taxBalance[i] << endl;
				else if (taxBalance[i] < -2)
					(taxBalance[i] < 0) ?	
					cout << "Year (" << taxYear[i] << ") refund due: " << std::setprecision(2)  << fixed << -taxBalance[i] << endl :
					cout << "Year (" << taxYear[i] << ") refund due: " << std::setprecision(2)  << fixed << taxBalance[i] << endl;
				else 
					cout << "Year (" << taxYear[i] << ") No balance owing or refund due!" << endl;
			}
		}

		else
			cout << "Account object is empty!" << endl;
	}
}
