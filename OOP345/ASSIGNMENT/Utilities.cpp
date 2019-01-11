// Milestone 1 - Assembly Line
// Utilities.cpp
// Author: Chaz-Lee Pierre
// Date: 2018-11-10

#include "Utilities.h"

Utilities::Utilities() : field_width(1) {}

void Utilities::setFieldWidth(size_t fw) {
	field_width = fw;
}

size_t Utilities::getFieldWidth() const {
	return field_width;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
	std::string token;
	try {
		token = str.substr(next_pos);
		size_t current_pos = token.find(delimiter);
		if (current_pos != std::string::npos) {
			token = token.substr(0, current_pos);
			if (token.length() == 0u)
				throw std::string("**Error! A token has a length of zero, correct input file.**");
			if (token.length() > field_width)
				field_width = token.length();
			next_pos += current_pos + 1;
			more = true;
		}
		else {
			more = false;
		}
		return token;
	} catch (std::string error) {
		token = error;
	}
	return token;
}

void Utilities::setDelimiter(const char d) {
	delimiter = d;
}

const char Utilities::getDelimiter() const {
	return delimiter;
}
