/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
// Date: May 25th 2018
// Author: Chaz Pierre
// Description: Define display function
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

namespace sict {
	void display(const Kingdom &kingdom) {
		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
	}

	void display(const Kingdom *kingdom, int size) {
		int totalPop = 0;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << kingdom[i].m_name << ", population " << kingdom[i].m_population << endl;
			totalPop += kingdom[i].m_population; // calculate total
		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << totalPop << endl;
		cout << "------------------------------" << endl;
	}
}
