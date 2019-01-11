// Workshop 5 - Lambda Functions
// Grades.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-10-10

#include <string>
#include <fstream>
#include <iomanip>
#include "Grades.h"

namespace sict {
	Grades::Grades(const char *path) {
		std::ifstream file;
		file.open(path);
		if (file.good()) {
			for (std::string buffer; std::getline(file, buffer); _size++); // get line count
			file.clear();
			file.seekg(0, std::ios::beg);
			_students = new std::string[_size];
			_grades = new double[_size];
			for (size_t i = 0u; i < _size; i++) {
				std::string buffer;
				std::getline(file, buffer);
				size_t position = buffer.find(' ');
				_students[i] = buffer.substr(0, position);
				buffer.erase(0, position + 1);
				_grades[i] = std::stod(buffer);
			}
		}
		else {
			_students = nullptr;
			_grades = nullptr;
			_size = 0;
			throw 1;
		}
	}

	Grades::~Grades() {
		delete[] _students;
		_students = nullptr;
		delete[] _grades;
		_grades = nullptr;
	}
}