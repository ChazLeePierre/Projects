// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22

#include <iostream>
#include <fstream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::ofstream ofs("Lab5Output.txt");

	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	// Workshop 5 - Lambda Functions
	// W5.cpp
	// Author: Chaz-Lee Pierre
	// Date: 2018-10-10 
	// Created the exception-handled Lambda Function 

	try {
		sict::Grades grades(argv[1]);
		auto letter = [](double grade) {
			if (grade < 50)
				return Letter::F;
			else if (grade < 55)
				return Letter::D;
			else if (grade < 60)
				return Letter::D_;
			else if (grade < 65)
				return Letter::C;
			else if (grade < 70)
				return Letter::C_;
			else if (grade < 75)
				return Letter::B;
			else if (grade < 80)
				return Letter::B_;
			else if (grade < 90)
				return Letter::A;
			else if (grade >= 90)
				return Letter::A_;
			else
				return Letter::X;
		};

		grades.displayGrades(ofs, letter);
	}

	catch (int) {
		std::cerr << "Error: Could not open file " << argv[1] << ". Make sure it's in the same location as " << argv[0] << '.' << std::endl;
	}

	catch (...) {
		std::cerr << "Unknown error." << std::endl;
	}

	ofs.close();
}