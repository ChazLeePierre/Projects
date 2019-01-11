///////////////////////////////////////////////////////////
// Milestone One
// Date.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#include "Date.h"

namespace AMA {

	// number of days in month mon_ and year year_
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	void Date::errCode(int errorCode) { // set error_code equal to argument
		error_code = errorCode;
	}

	bool Date::bad() const { // if error_code does not equal no error, return true (bad)
		return (error_code == NO_ERROR) ? false : true;
	}

	Date::Date() { // set date to safe empty state
		date_year = 0;
		date_month = 0;
		date_day = 0;
		compare_value = 0;
		errCode(NO_ERROR);
	}

	Date::Date(int year, int month, int day) { // constructor w/ date arguments
		// initialize dates
		date_year = year;
		date_month = month;
		date_day = day;
		errCode(NO_ERROR);
		compare_value = date_year * 372 + date_month * 13 + date_day;
		
		// if anything wrong with dates, set error code
		if (date_day < 1 || date_day > mdays(date_month, date_year))
			errCode(DAY_ERROR);
		else if (date_year < min_year || date_year > max_year) 
			errCode(YEAR_ERROR);
		else if (date_month < 1 || date_month > 12) 
			errCode(MON_ERROR);
		else if (date_year == 0 && date_month == 0 && date_day == 0)
			errCode(CIN_FAILED);
		else errCode(NO_ERROR);

		// if there is an error code, set to a safe empty state
		if (bad()) {
			date_year = 0;
			date_month = 0;
			date_day = 0;
			compare_value = 0;
		}
		
	}

	std::ostream& Date::write(std::ostream& ostr) const { // output date data to an ostream object
		ostr << date_year << "/" << std::setfill('0') << std::setw(2) << date_month << "/" << std::setfill('0') << std::setw(2) << date_day;
		return ostr;
	}

	std::istream& Date::read(std::istream& istr) { // input date data to an istream object
		int nofail;
		char fail;

		Date();

		// year
		if (istr >> nofail && !istr.fail())
			date_year = nofail;
		else
			errCode(CIN_FAILED);
		if (istr >> fail && istr.fail()) 
			errCode(CIN_FAILED);
		
		// month
		if (istr >> nofail && !istr.fail()) 
			date_month = nofail; 
		else 
			errCode(CIN_FAILED);
		if (istr >> fail && istr.fail()) 
			errCode(CIN_FAILED);

		// day
		if (istr >> nofail && !istr.fail())
			date_day = nofail;
		else
			errCode(CIN_FAILED);
	
		if (!bad()) {
			if (date_year < min_year || date_year > max_year) 
				errCode(YEAR_ERROR);
			if (date_month < 1 || date_month > 12)
				errCode(MON_ERROR);
			else if (date_day < 1 || date_day > mdays(date_month, date_year))
				errCode(DAY_ERROR);
		}

		if (bad()) {
			date_year = 0;
			date_month = 0;
			date_day = 0;
			compare_value = 0;
		}

		return istr;
	}

	int Date::errCode() const { // return error code
		return error_code;
	}

	bool Date::operator==(const Date& rhs) const {
		return (compare_value == rhs.compare_value) ? true : false;
	}

	bool Date::operator!=(const Date& rhs) const {
		return (compare_value != rhs.compare_value) ? true : false;
	}

	bool Date::operator>=(const Date& rhs) const {
		return (compare_value >= rhs.compare_value) ? true : false;
	}

	bool Date::operator<=(const Date& rhs) const {
		return (compare_value <= rhs.compare_value) ? true : false;
	}

	bool Date::operator<(const Date& rhs) const {
		return (compare_value < rhs.compare_value) ? true : false;
	}

	bool Date::operator>(const Date& rhs) const {
		return (compare_value > rhs.compare_value) ? true : false;
	}

	std::ostream& operator<<(std::ostream& ostr, const Date& rhs) {
		return rhs.write(ostr);
	}
	std::istream& operator >> (std::istream& istr, Date& rhs) {
		return rhs.read(istr);
	}
}
