// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 2.1
// June 6th 2018
// Chaz Pierre
// 123206179
// cpierre4@myseneca.ca
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

#pragma once
#define max_yrs 4

namespace sict { 
	// limits
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	// set and get functions
	class CRA_Account { 
	int taxYear[max_yrs];
	double taxBalance[max_yrs];
	int countYears;
	char familyNameStored[max_name_length];
	char givenNameStored[max_name_length];
	int sin;
	public:
		void set(int year, double balance);
		void set(const char* familyName, const char* givenName, int sin);
	        bool isSINvalid(int sin) const;
		bool isEmpty() const;
		void display() const;
	};
}
