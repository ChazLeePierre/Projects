/**********************************************************^M
///////////////////////////////////////////////////////////
// Workshop 6: Class with a Resource
// Contact.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/
#pragma once
namespace sict {
	class Contact {
		char con_name[20];
		long long* con_phones;
		int con_size;
	public: 
		Contact(); // constructor that sets current object to a safe empty state
		Contact(const char*, const long long*, int); // copies valid numbers into allocated array
		~Contact(); // deallocates any memory that has been allocated dynamically
		bool isEmpty() const; // checks if the current object is in a safe empty state
		void display() const; // displays formatted data to the user
		bool isValid(long long phone) const; // checks if the current number is valid
	};
}
