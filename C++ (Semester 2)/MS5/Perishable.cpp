///////////////////////////////////////////////////////////
// Milestone Five
// Perishable.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#include "Perishable.h"
using namespace std;

namespace AMA {

	Perishable::Perishable() : Product::Product('P') { // set exp date to a safe empty state
		expiry_date = Date();
	}

	fstream& Perishable::store(fstream& file, bool newLine) const { // store to fstream
		Product::store(file, false);
		file << "," << expiry_date;
		if (newLine) 
			file << '\n';
		return file;
	}

	fstream& Perishable::load(fstream& file){ // load from fstream
		Product::load(file);
		for (int i = 0; i < 8; i++) 
			file.ignore(2000, ',');
		expiry_date.read(file);
		return file;
	}

	ostream& Perishable::write(ostream& os, bool linear) const { // write to ostream
		os << setfill(' ');
		if (Product::write(os, linear)) {
			if (Product::isClear())
				(linear) ? os << expiry_date : os << endl << " Expiry date: " << expiry_date;
		}
		return os;
	}

	istream& Perishable::read(istream& is) { // read from istream
		Date temp_Date;
		if (Product::read(is)) {
			cout << " Expiry date (YYYY/MM/DD): ";
			is >> temp_Date;
			if (temp_Date.errCode() != 0) {
				is.setstate(ios::failbit);
				switch (temp_Date.errCode()) {
				case 1:
					Product::message("Invalid Date Entry");
					break;
				case 2:
					Product::message("Invalid Year in Date Entry");
					break;
				case 3:
					Product::message("Invalid Month in Date Entry");
					break;
				case 4:
					Product::message("Invalid Day in Date Entry");
					break;
				default:
					break;
				}
			}
		}
		if (!is.fail())
			expiry_date = temp_Date;
		return is;
	}

	const Date& Perishable::expiry() const { // return exp date
		return expiry_date;
	}
}
