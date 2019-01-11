#include "Product.h"

w6::Product::Product(int product_number, double price) {
	this->_product_number = product_number;
	this->_price = price;
}

double w6::Product::getPrice() const {
	return _price;
}

void w6::Product::display(std::ostream & os) const {
	os << std::setw(10) << _product_number << std::setw(10) << std::fixed << _price;
}
