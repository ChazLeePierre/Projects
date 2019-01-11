// Workshop 6 - STL Containers
// w6.cpp

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"

void display(std::ofstream& ofs, std::vector<const w6::iProduct*>& product_vector) {
	double total = 0.0;
	ofs << "Product No" << std::setw(10) << "Cost";
	ofs << " Taxable" << std::endl;
	ofs.precision(2);
	for (size_t i = 0; i < product_vector.size(); i++) {
		ofs << *product_vector[i] << std::endl;
		total += product_vector[i]->getPrice();
	}
	ofs << std::setw(10) << "Total";
	ofs << std::setw(10) << std::fixed << total;
}

int main(int argc, char** argv) {

	std::ofstream ofs("Lab6Output.txt");

	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open productList " << argv[1] << "***\n";
		return 2;
	}
	ofs << std::fixed << std::setprecision(2);
	try {
		std::vector<const w6::iProduct*> product_vector;

		if (productList.good()) {
			size_t count = 0u;
			for (std::string temp; std::getline(productList, temp); count++) {}
			productList.clear();
			productList.seekg(0, std::ios::beg);
			for (size_t i = 0u; i < count; i++)
				product_vector.push_back(w6::readProduct(productList));
			display(ofs, product_vector);
		}
	}
	catch (std::string& error) {
		std::cerr << error;
		return 2;
	}

	std::cout << "Results are in Lab6Output.txt\nPress any key to continue ... ";
	std::cin.get();

	ofs.close();
}