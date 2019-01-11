// Workshop 2 - Copy and Move Semantics
// Text.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-09-12

#include "Text.h"

namespace w2 {
	// I thought std::ifstream would have some sort of line counting function
	// but I guess not, so I implimented one in a seperate function.
	size_t calcLineCount(std::ifstream& file) {
		std::string line;
		size_t linecount = 0;
		while (!file.eof()) {
			getline(file, line);
			linecount++;
		}
		return linecount;
	}

	// No-Arg Constructor
	Text::Text() {
		_linecount = 0;
		_Text = nullptr;
	}

	// One-Arg Constructor
	Text::Text(const std::string input) {
		std::ifstream file;
		file.open(input);
		if (file.good()) {
			_linecount = calcLineCount(file);
			_Text = new std::string[_linecount];
			for (size_t i = 0; i < _linecount; i++)
				std::getline(file, _Text[i]);
		}
		else
			*this = Text();
		file.close();
	}

	// Copy Constructor
	Text::Text(const Text &object) {
		*this = object;
	}

	// Move Constructor
	Text::Text(Text &&object){
		*this = std::move(object);
	}

	// Copy Assignment Operator
	Text& Text::operator=(const Text& object) {
		if (this != &object) {
			_linecount = object._linecount;
			_Text = new std::string[_linecount];
			for (size_t i = 0; i < _linecount; i++)
				_Text[i] = object._Text[i];
		}
		return *this;
	}

	// Move Assignment Operator
	Text& Text::operator=(Text&& object) {
		if (this != &object) {
			_linecount = object._linecount;
			_Text = object._Text;
			object._linecount = 0;
			object._Text = nullptr;
		}
		return *this;
	}

	// Destructor
	Text::~Text() {
		delete[] _Text;
		_Text = nullptr;
	}

	// Helper Function - return _linecount
	size_t Text::size() const {
		return _linecount;
	}
}