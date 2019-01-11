// Workshop 2 - Copy and Move Semantics
// Text.h
// Author: Chaz-Lee Pierre
// Date: 2018-09-12

#pragma once
#include <iostream>
#include <string>
#include <fstream>

namespace w2 {
	class Text {
		std::string* _Text; // Array of file content
		size_t _linecount; // Number of records
	public:
		Text(); // No-Arg Constructor
		Text(const std::string input); // One-Arg Constructor
		Text(const Text &object); // Copy Constructor
		Text(Text &&object); // Move Constructor
		Text& operator=(const Text& object); // Copy Assignment Operator
		Text& operator=(Text&& object); // Move Assignment Operator
		~Text(); // Destructor
		size_t size() const; // Helper Function - return _linecount
	};
	size_t calcLineCount(std::ifstream& file); // Calculate _linecount
}