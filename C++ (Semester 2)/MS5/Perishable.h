///////////////////////////////////////////////////////////
// Milestone One
// Perishable.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#pragma once

#include "Date.h"
#include "Product.h"
using namespace std;

namespace AMA {
	class Perishable : public Product {
		Date expiry_date;
	public:
		Perishable();
		fstream& store(fstream& file, bool newLine = true) const;
		fstream& load(fstream& file);
		ostream& write(ostream& os, bool linear) const;
		istream& read(istream& is);
		const Date& expiry() const;
	};
}
