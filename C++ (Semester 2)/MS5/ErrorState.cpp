///////////////////////////////////////////////////////////
// Milestone Two
// ErrorState.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "ErrorState.h"

namespace AMA {
	ErrorState::ErrorState(const char* errorMessage) { 
		// if errorMessage == nullptr, set object to a safe empty state
		// else allocate memory for message, & copy message into allocated memory
		error_message = nullptr;
		(errorMessage == nullptr) ? message('\0') : message(errorMessage);
	}

	ErrorState::~ErrorState() { // deconstructor: deallocate memory
		delete [] error_message;
	}

	void ErrorState::clear() { // empty message
		error_message[0] = '\0';
	}

	bool ErrorState::isClear() const { // check if message empty
		return (error_message[0] == '\0') ? true : false;
	}

	void ErrorState::message(const char* str) { 
		if (str != nullptr) {
			const int str_length = strlen(str);
			// delete any previously stored message if there is any
			if (error_message != nullptr) { 
				clear();
				delete [] error_message;
				error_message = nullptr;
			}
			// allocate memory to copy string
			error_message = new char[str_length + 1]; 
			strncpy(error_message, str, str_length);
			error_message[str_length] = '\0';
		}
		else { // if argument is empty, allocate memory and copy null terminator
			error_message = new char[1];
			error_message[0] = '\0';
		}
	}
	const char* ErrorState::message() const { // returns stored message
		return error_message;
	}
	std::ostream& operator<< (std::ostream& os, const ErrorState& em) { // sends message to ostream if message exists
		if (!em.isClear()) { 
			os << em.message();
		}
		return os;
	}
}