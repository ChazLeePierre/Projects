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
		char con_name[20]; // name
		long long* con_phones; // pointer to an array of phones
		int con_size; // size of array
	public: 
		Contact(); // constructor that sets current object to a safe empty state
		Contact(const char*, const long long*, int); // copies valid numbers into allocated array
		Contact(const Contact &copy); // copy assignment
		~Contact(); // deallocates any memory that has been allocated dynamically
		Contact& operator=(const Contact& copy); // overloaded assignment operator to copy content of object into the current object
		Contact& operator+=(long long addcopy); // same as above excepts appends existing current object
		bool isEmpty() const; // checks if the current object is in a safe empty state
		void display() const; // displays formatted data to the user
		bool isValid(long long phone) const; // checks if the current number is valid
	};
}
