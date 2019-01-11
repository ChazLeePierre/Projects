// Workshop 6 - STL Containers
// TaxableProduct.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-10-26

#pragma once

#include "Product.h"

namespace w6 {
	class TaxableProduct : public Product {
		char _tax_character;
		enum class tax {NONE, HST, PST};
		const double _tax_rate[3] = { 1.00, 1.13, 1.08 };
	public:
		TaxableProduct() : _tax_character(' ') {} // Safe-empty state
		TaxableProduct(int product_number, double price, char tax_character); // Initialize
		double getPrice() const; // Return price with tax
		void display(std::ostream&) const; 
	};
}