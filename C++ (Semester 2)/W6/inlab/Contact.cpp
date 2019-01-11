/**********************************************************^M
///////////////////////////////////////////////////////////
// Workshop 6: Class with a Resource
// Contact.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Contact.h"
using namespace std;

namespace sict {
	Contact::Contact() { // constructor with no parameters
		// set object to safe empty state
		con_name[0] = '\0';
		con_phones = nullptr;
		con_size = -1;
	}

	bool Contact::isValid(long long phone) const {
		return ( // check for valid 12 digit phone number
			phone < (long long)1e12 // cannot be greater than 12 digits
			&& phone >= (long long)1e11 // must be 12 digits with first digit of country code must not be 0
			&& (phone / (long long)1e10) % 10 != 0 // second digit of country code must not be 0
			&& (phone / (long long)1e9) % 10 != 0 // first digit of area code must not be 0
			&& (phone / (long long)1e6) % 10 != 0 // first digit of number must not be 0
			) || ( // check for valid 11 digit phone number
				phone < (long long)1e11 // cannot be greater than 11 digits
				&& phone >= (long long)1e10 // must be 11 digits with first digit of country code must not be 0
				&& (phone / (long long)1e9) % 10 != 0 // first digit of area code must not be 0
				&& (phone / (long long)1e6) % 10 != 0 // first digit of number must not be 0
				);
	}

	Contact::Contact(const char* name, const long long* phones, int size) { // constructor with three parameters 
		if (name != nullptr && name[0] != '\0' && size >= 0) { // validates data
			// calculate number of valid phone numbers
			int validNo = 0;
			long long* tempNum = new long long[size];
			for (int i = 0; i < size; i++) {
				if (isValid(phones[i])) {
					tempNum[validNo] = phones[i];
					validNo++;
				}
			}
			strncpy(con_name, name, 20); // assigns inputted name to the current object name
			if (con_name[19] != '\0') 
				con_name[19] = '\0';
			// assigns inputted valid phone numbers into the current object phone number
			con_size = validNo;
			con_phones = new long long[validNo];
			for (int i = 0; i < validNo; i++)
				con_phones[i] = tempNum[i];
			delete[] tempNum; // deallocate dynamic memory
		}
		else
			*this = Contact(); // if data is not valid, set current object to a safe empty state
	}

	Contact::~Contact() { // deconstructor
		delete[] con_phones; // deallocate dynamic memory
	}

	bool Contact::isEmpty() const {
		return con_name[0] == '\0' && con_phones == nullptr && con_size == -1 ? true : false; // if data is empty return true, if not, return false
	}

	void Contact::display() const {
		if (!isEmpty()) {
			Contact display = Contact(con_name, con_phones, con_size);
			//for (int i = 0; i < con_size; i++)
			//cout << con_phones[i];
			int country, area, num1, num2;
			// CONTACT_NAME
			cout << display.con_name << endl;
			for (int i = 0; i < display.con_size; i++) {
				// COUNTRY_CODE
				country = display.con_phones[i] / 1e10;
				cout << "(+" << country << ") ";
				display.con_phones[i] -= country * 1e10;
				// AREA_CODE
				area = display.con_phones[i] / 1e7;
				cout << area << " ";
				display.con_phones[i] -= area * 1e7;
				// NNN
				num1 = display.con_phones[i] / 1e4;
				cout << num1 << "-";
				display.con_phones[i] -= num1 * 1e4;
				// NNNN
				num2 = display.con_phones[i];
				cout << setfill('0') << setw(4) << num2 << endl;
			}
		} else
			cout << "Empty contact!" << endl; // if empty, display Empty contact!
	}
}
