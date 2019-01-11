///////////////////////////////////////////////////////////
// Milestone Three
// Product.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <sstream>
#include <string>
#include "Product.h"
using namespace std;

namespace AMA {
	void Product::name(const char* name) { // set product name
		if (product_name != nullptr) {
			delete [] product_name;
			product_name = nullptr;
		}

		if (name != nullptr) {
			if (strlen(name) > max_name_length) {
				product_name = new char[max_name_length + 1];
				strncpy(product_name, name, max_name_length);
				product_name[strlen(name)] = '\0';
			}

			else {
				product_name = new char[strlen(name) + 1];
				strcpy(product_name, name);
				product_name[strlen(name)] = '\0';
			}
		}

	}

	const char* Product::name() const { // return product name if not empty
		return (product_name == nullptr || product_name[0] == '\0') ? nullptr : product_name;
	}

	const char* Product::sku() const { // return product SKU
		return product_SKU;
	}

	const char* Product::unit() const { // return unit description
		return product_unit_desc;
	}

	bool Product::taxed() const { // return taxable
		return isTaxable;
	}

	double Product::price() const { // return price
		return product_unit_price;
	}

	double Product::cost() const { // return cost with any applicable tax
		return (isTaxable) ? product_unit_price + (product_unit_price * current_taxrate) : product_unit_price;
	}

	void Product::message(const char* error_message) { // sets error message
		product_ErrorState.message(error_message);
	}

	bool Product::isClear() const { // checks for error
		return product_ErrorState.isClear();
	}

	Product::Product(char product_type_) { // safe empty state
		product_type = product_type_;
		product_SKU[0] = '\0';
		product_unit_desc[0] = '\0';
		product_name = nullptr;
		product_quantity_onhand = 0;
		product_quantity_needed = 0;
		product_unit_price = 0;
		isTaxable = true;
	}

	Product::Product(const char* sku, const char* product_name_, const char* product_unit_desc_, int product_quantity_onhand_, bool isTaxable_, double product_unit_price_, int product_quantity_needed_) { // initialize product object
		product_name = nullptr;
		*this = Product();
		strncpy(product_SKU, sku, max_sku_length);
		product_SKU[max_sku_length] = '\0';
		name(product_name_);
		strncpy(product_unit_desc, product_unit_desc_, max_unit_length);
		product_unit_desc[max_unit_length] = '\0';
		product_quantity_onhand = product_quantity_onhand_;
		product_quantity_needed = product_quantity_needed_;
		isTaxable = isTaxable_;
		product_unit_price = product_unit_price_;
	}

	Product::Product(const Product& productCopy_) { // copy constructor
		if (!productCopy_.isEmpty()) {
			product_name = nullptr;
			*this = productCopy_;
		}
	}

	Product& Product::operator=(const Product& productCopy_) { // copy assignment operator
		if (this == &productCopy_) 
			return *this;
		else {
			product_type = productCopy_.product_type;
			strcpy(product_SKU, productCopy_.product_SKU);
			name(productCopy_.product_name);
			strcpy(product_unit_desc, productCopy_.product_unit_desc);
			product_quantity_onhand = productCopy_.product_quantity_onhand;
			product_quantity_needed = productCopy_.product_quantity_needed;
			isTaxable = productCopy_.isTaxable;
			product_unit_price = productCopy_.product_unit_price;
			product_ErrorState.message(productCopy_.product_ErrorState.message());
			return *this;
		}
	}

	Product::~Product() { // deconstructor: deallocate memory
		delete [] product_name;
		product_name = nullptr;
	}

	fstream& Product::store(fstream& file, bool newLine) const { // store in file
		file << product_type << "," << product_SKU << "," << product_name << "," << product_unit_desc << "," << isTaxable << "," << product_unit_price << "," << product_quantity_onhand << "," << product_quantity_needed;
		if (newLine) 
			file << endl;
		return file;
	}

	fstream& Product::load(fstream& file) { // load from file
		const int size = 7;
		string String[size];
		string line;
		getline(file, line);
		stringstream stream(line);
		int i = 0;
		while (getline(stream, String[i], ',')) {
			if (i == size - 1) 
				break;
			i++;
		}
		Product product = Product(String[0].c_str(), String[1].c_str(), String[2].c_str(), stoi(String[5]), stoi(String[3]), stof(String[4]), stoi(String[6]));
		*this = product;
		return file;
	}

	ostream& Product::write(ostream& ostr, bool linear) const { // write to ouput stream
		if (!product_ErrorState.isClear())
		       	ostr << product_ErrorState;	
		else {
			if (linear) {
				ostr << left << setw(max_sku_length) << product_SKU << "|";
				ostr << left << setw(20) << product_name << "|";
				ostr << fixed << setprecision(2) << right << setw(7) << cost() << "|";
				ostr << right << setw(4) << product_quantity_onhand << "|";
				ostr << left << setw(10) << product_unit_desc << "|";
				ostr << right << setw(4) << product_quantity_needed << "|";
			}

			else {
				ostr << " Sku: " << product_SKU << endl;
				ostr << " Name (no spaces): " << product_name << endl;
				ostr << " Price: " << price() << endl;
				ostr << " Price after tax: ";
				(taxed()) ? ostr << cost() << endl : ostr << "N/A" << endl;
				ostr << " Quantity on Hand: " << product_quantity_onhand;
				if (product_unit_desc[0] != 0)
					ostr << " " << product_unit_desc;	
				ostr << endl;
				ostr << " Quantity needed: " << product_quantity_needed;
			}
		} 

		return ostr;
	}

	istream& Product::read(istream& istr) { // read from input stream
		char* SKU_ = new char[max_sku_length + 1];
		char* name = new char[max_name_length + 1];
		char* unit = new char[max_unit_length + 1];
		int onhand, needed;
		double price;
		char taxed;
		bool isTaxable_;
		cout << " Sku: ";
		istr >> SKU_;
		cout << " Name (no spaces): ";
		istr >> name;
		cout << " Unit: ";
		istr >> unit;
		cout << " Taxed? (y/n): ";
		istr >> taxed;
		if (taxed != 'y' && taxed != 'Y' && taxed != 'n' && taxed != 'N') {
			istr.setstate(ios::failbit);
			product_ErrorState.message("Only (Y)es or (N)o are acceptable");
		} else {
			isTaxable_ = (taxed == 'y' || taxed == 'Y') ? true : false;
		}
		if (!istr.fail()) {
			cout << " Price: ";
			istr >> price;
			if (istr.fail()) 
				product_ErrorState.message("Invalid Price Entry");
		}

		if (!istr.fail()) {
			cout << " Quantity on hand: ";
			istr >> onhand;
			if (istr.fail()) 
				product_ErrorState.message("Invalid Quantity Entry");
		}

		if (!istr.fail()) {
			cout << " Quantity needed: ";
			istr >> needed;
			if (istr.fail()) 
				product_ErrorState.message("Invalid Quantity Needed Entry");
		}

		if (!istr.fail()) {
			Product temp = Product(product_type);
			delete[] temp.product_name;
			temp.product_name = new char[strlen(name) + 1];
			strcpy(temp.product_SKU, SKU_);
			strcpy(temp.product_name, name);
			strcpy(temp.product_unit_desc, unit);
			temp.product_quantity_onhand = onhand;
			temp.product_quantity_needed = needed;
			temp.isTaxable = isTaxable_;
			temp.product_unit_price = price;
			*this = temp;
		}

		delete[] SKU_;
		SKU_ = nullptr;
		delete[] name;
		name = nullptr;
		delete[] unit;
		unit = nullptr;
		istr.get();
		return istr;
	}

	bool Product::operator==(const char* sku) const { // check if SKU is equivalent
		return (strcmp(product_SKU, sku) == 0);
	}

	double Product::total_cost() const { // return total cost
		return cost() * product_quantity_onhand;
	}

	void Product::quantity(int product_quantity_) { // sets the quantity available
		product_quantity_onhand = product_quantity_;
	}

	bool Product::isEmpty() const { // checks if product is in a safe empty state
		return (product_type == 'N' && product_SKU[0] == '\0' && product_unit_desc[0] && '\0' && product_quantity_onhand == 0 && product_quantity_needed == 0 && product_unit_price == 0 && isTaxable == true && product_name == nullptr);
	}

	int Product::qtyNeeded() const { // returns the quantity needed
		return product_quantity_needed;
	}

	int Product::quantity() const { // returns the quantity available
		return product_quantity_onhand;
	}

	bool Product::operator>(const char* sku) const { // checks if product sku is larger than argument sku
		return (product_SKU > sku);
	}

	bool Product::operator>(const iProduct& product) const { //checks if product name is larger than argument sku
		return (product_name > product.name());
	}

	int Product::operator+=(int product_quantity_) { // adds argument to quantity available and returns quantity available
		product_quantity_onhand += product_quantity_;
		return product_quantity_onhand;
	}

	ostream& operator<<(ostream& ostr, const iProduct& product) { // <<
		return product.write(ostr, true);
	}

	istream& operator>>(istream& istr, iProduct& product) { // >>
		return product.read(istr);
	}

	double operator+=(double& add, const iProduct& product) { // adds
		add += product.total_cost();
		return add;
	}
}
