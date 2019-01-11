///////////////////////////////////////////////////////////
// Milestone One
// Date.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>

namespace AMA {
	int const min_year = 2000; // min year
	int const max_year = 2030; // max year
	int const NO_ERROR = 0; // no error
	int const CIN_FAILED = 1; // cin failed
	int const YEAR_ERROR = 2; // year error
	int const MON_ERROR = 3; // month error
	int const DAY_ERROR = 4; // day error
	class Date { // Date class
		int date_year; // year
		int date_month; // month
		int date_day; // day
		int compare_value; // compare value
		int error_code; // error code
		int mdays(int, int)const; 
		void errCode(int errorCode); // set error code
	public:
		Date(); // constructor no arg
		Date(int year, int month, int day); // constructor three args
		std::ostream& write(std::ostream& ostr) const; // output to ostream obj
		std::istream& read(std::istream& istr); // input to istream obj
		int errCode() const; // return error code
		bool bad() const; // check if any error code
		bool operator==(const Date& rhs) const; // == 
		bool operator!=(const Date& rhs) const; // !=
		bool operator>=(const Date& rhs) const; // >=
		bool operator<=(const Date& rhs) const; // <=
		bool operator>(const Date& rhs) const; // >
		bool operator<(const Date& rhs) const; // <

	};
	std::ostream& operator<<(std::ostream& ostr, const Date& rhs); // <<
	std::istream& operator>>(std::istream& istr, Date& rhs); // <<
}

