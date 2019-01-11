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
			int count = 0;
			for (int i = 0; i < size; i++) {
				if (isValid(phones[i])) 
					validNo++;
			}
			strncpy(con_name, name, 20); // assigns inputted name to the current object name
			if (con_name[19] != '\0') 
				con_name[19] = '\0';
			// assigns inputted valid phone numbers into the current object phone number
			con_size = validNo;
			con_phones = new long long[validNo];
			for (int i = 0; i < validNo; i++) {
				if (isValid(phones[i])) {
					con_phones[count] = phones[i];
					count++;
				}
			}
		}
		else
			*this = Contact(); // if data is not valid, set current object to a safe empty state
	}

	Contact::Contact(const Contact &copy) {
		if (this != &copy) // if the current object's address is different than the address of the copy object, 
			*this = copy; // set the current object equal to the copy object
	}

	Contact::~Contact() { // deconstructor
		delete[] con_phones; // deallocate dynamic memory
		con_phones = nullptr;
	}

	bool Contact::isEmpty() const {
		return con_name[0] == '\0' && con_phones == nullptr && con_size <= 0 ? true : false; // if data is empty return true, if not, return false
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl; // if empty, display Empty contact!
		} else {
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
		}	
	}

	Contact& Contact::operator=(const Contact& copy) {
		if (this == &copy) return *this; // if addresses match, return the current object
		if (!copy.isEmpty()) { 
			strncpy(con_name, copy.con_name, 20); // assigns inputted name to the current object name
			if (con_name[19] != '\0')
				con_name[19] = '\0';
			con_size = copy.con_size; // copy over copy object phones into the current object's phones
			con_phones = new long long[con_size];
			for (int i = 0; i < con_size; i++)
				con_phones[i] = copy.con_phones[i];
		}
		else { // if object is empty, reset values
			con_name[0] = '\0';
			con_phones = nullptr;
			con_size = -1;
		}
		return *this;
	}

	Contact& Contact::operator+=(long long addcopy) {
		if (isValid(addcopy) && !isEmpty()) { // if valid and not empty
			con_size++; // add one to size
			if (con_size > 1) { // if the size is greater than 1
				long long * tempPhone = new long long[con_size - 1]; // copy current object phones into copy's phones
				tempPhone = con_phones;
				con_phones = new long long[con_size];
				for (int i = 0; i < con_size; i++) {
					if (i == con_size - 1) {
						delete[] tempPhone;
						con_phones[i] = addcopy;
					}
					else
						con_phones[i] = tempPhone[i];
				}
			}
			else {
				if (con_size == 0) con_size++;
				con_phones = new long long[con_size];
				con_phones[con_size - 1] = addcopy;
			}
		}
		return *this;
	}

} 
