#pragma once

#include "iProduct.h"

namespace w6 {
	class Product : public iProduct {
	protected:
		int _product_number;
		double _price;
	public:
		Product() : _product_number(0), _price(0) {}
		Product(int product_number, double price);
		double getPrice() const;
		void display(std::ostream&) const;
	};
}