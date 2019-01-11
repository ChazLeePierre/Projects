/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Date: May 25th 2018
// Author: Chaz Pierre
// Description: Enter and display Kingdom information
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(sict::Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array
	Kingdom* pKingdom = nullptr;

	// introduction
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;
	
	// get Kingdom information
	pKingdom = new Kingdom[count]; // dynamically allocated array
	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	Kingdom* pKingdomExtended = new Kingdom[count + 1]; // increase array size
	for (int i = 0; i < count; i++) { // copy elements from old array to new
		pKingdomExtended[i] = pKingdom[i];
	}

	delete[] pKingdom; // deallocate dynamic memory
	pKingdom = nullptr;
	pKingdom = pKingdomExtended; // set data from new array back to old

	// add the new Kingdom
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	count++;
	read(pKingdom[count - 1]);
	cout << "==========\n" << endl;

	// testing that the overload of "display(...)" works
	display(pKingdom, count);
	cout << endl;
	
	delete[] pKingdom; // deallocate dynamic memory
	pKingdom = nullptr;
	return 0;
}

// read accepts data for a Kingdom from standard input
void read(sict::Kingdom& kingdom) {

	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
}
