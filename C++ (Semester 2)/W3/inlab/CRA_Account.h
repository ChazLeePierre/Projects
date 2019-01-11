// Workshop 3: Classes and Privacy
// CRA_Account.h
// Version 2.1
// June 1st 2018
// Chaz Pierre
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

namespace sict { 
	// limits
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	
	// set and get functions
	class CRA_Account { 
	public:
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
	};
}
