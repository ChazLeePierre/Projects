///////////////////////////////////////////////////////////
// Milestone Three
// Product.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include "ErrorState.h"
#include "iProduct.h"

namespace AMA {

	const unsigned int max_sku_length = 7;
	const unsigned int max_unit_length = 10;
	const unsigned int max_name_length = 75;
	const double current_taxrate = 0.13;

	class Product : public iProduct {
		char product_type;
		char product_SKU[max_sku_length + 1];
		char product_unit_desc[max_unit_length + 1];
		char* product_name;
		int product_quantity_onhand;
		int product_quantity_needed;
		double product_unit_price;
		bool isTaxable;
		ErrorState product_ErrorState;

	protected:
		void name(const char* name);
		const char* name() const;
		const char* sku() const;
		const char* unit() const;
		bool taxed() const;
		double price() const;
		double cost() const;
		void message(const char* error_message);
		bool isClear() const;

	public:
		Product(char product_type_ = 'N');
		Product(const char* sku, const char* product_name_, const char* product_unit_desc_, int product_quantity_onhand_ = 0, bool isTaxable_ = true, double product_unit_price_ = 0, int product_quantity_needed_ = 0);
		Product(const Product& productCopy_);
		Product& operator=(const Product& productCopy_);
		~Product();
		std::fstream& store(std::fstream& file, bool newLine=true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& ostr, bool linear) const;
		std::istream& read(std::istream& istr);
		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int product_quantity_);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char* sku) const;
		bool operator>(const iProduct& product) const;
		int operator+=(int product_quantity_);

	};

	std::ostream& operator<<(std::ostream& ostr, const iProduct& product);
	std::istream& operator>>(std::istream& istr, iProduct& product);
	double operator+=(double& add, const iProduct& product);

}
