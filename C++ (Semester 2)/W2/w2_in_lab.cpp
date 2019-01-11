/***********************************************************
 * s << std::setw(13) << std::left << std::fixed << name;
 *
 * 	os << "[" << serialNumber << "] Quantity " << Quantity << "   Description: " << description << std::endl;
 *
 * 	}os << std::setw(13) << std::left << std::fixed << name;
 *
 * 		os << "[" << serialNumber << "] Quantity " << Quantity << "   Description: " << description << std::endl;
 *
 * 		}
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
	pKingdom = new Kingdom[count];
	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st kingdom entered is" << endl
		<< "------------------------------" << endl;
	sict::display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;

	delete[] pKingdom;
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
