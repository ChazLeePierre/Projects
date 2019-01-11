/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date: May 25th 2018
// Author: Chaz Pierre
// Description: Define struct Kingdom and declare display function
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
#pragma once

namespace sict {
	struct Kingdom {
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom &kingdom);
}