///////////////////////////////////////////////////////////
// Milestone Two
// ErrorState.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////

#pragma once

namespace AMA {
	class ErrorState {
		char* error_message; // stored message
	public:
		explicit ErrorState(const char* errorMessage = nullptr); // set to safe empty state if msg empty, else allocate memory for errorMessage to be copied into stored message
		ErrorState(const ErrorState& em) = delete; // prevents copying
		ErrorState& operator=(const ErrorState& em) = delete; // prevents assignment
		virtual ~ErrorState(); // deallocate memory
		void clear(); // clear stored message
		bool isClear() const; // check if message is clear
		void message(const char* str); // copy str into stored msg
		const char* message() const; // return stored msg
	};
	std::ostream& operator<< (std::ostream& os, const ErrorState& em); // output stored message
}