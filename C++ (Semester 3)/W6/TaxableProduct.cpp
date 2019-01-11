// Workshop 6 - STL Containers
// TaxableProduct.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-10-25

#include "TaxableProduct.h"

w6::TaxableProduct::TaxableProduct(int product_number, double price, char tax_character) {
	this->_product_number = product_number;
	this->_price = price;
	this->_tax_character = tax_character;
}

double w6::TaxableProduct::getPrice() const {
	return (_tax_character == 'H') ? _price * _tax_rate[static_cast<int>(tax::HST)] : _price * _tax_rate[static_cast<int>(tax::PST)];
}

void w6::TaxableProduct::display(std::ostream& os) const {
	os << std::setw(10) << _product_number << std::setw(10) << std::fixed << _price;
	os.width();
	if (_tax_character == 'H') os << " HST";
	else if (_tax_character == 'P') os << " PST";
}

std::ostream& w6::operator<<(std::ostream& os, const iProduct& iProduct) {
	iProduct.display(os);
	return os;
}

w6::iProduct* w6::readProduct(std::ifstream& file) {
	iProduct* tempProduct;
	int _product_number;
	double _price;
	char _tax_character = '\0', type;
	size_t count = 0u;
	std::string line;
	std::getline(file, line);
	type = (std::count(line.begin(), line.end(), ' ') > 1) ? 't' : 'p'; // If line contains more than one space, it has a tax code.
	for (size_t pos = 0u; (pos = line.find(' ')) != std::string::npos; count++) { // Parse line, delimit by space
		if (count == 0u)
			_product_number = stoi(line.substr(0, pos));
		else if (count == 1u)
			_price = stod(line.substr(0, pos));
		line.erase(0, pos + 1);
	}
	if (count == 1u) _price = stod(line);
	else if (count == 2u) {
		_tax_character = line[0];
		if (!(_tax_character == 'H' || _tax_character == 'P')) 
			throw std::string("Error: tax code bad!");
	}
	tempProduct = (type == 't') ? new TaxableProduct(_product_number, _price, _tax_character) : new Product(_product_number, _price);
	return tempProduct;
}