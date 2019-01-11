/* -------------------------------------------
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Section: SHH
Date: March 26th 2018
----------------------------------------------
Assignment: 2
Milestone:  3
---------------------------------------------- */

#ifndef CONTACTS_H_
#define CONTACTS_H_

//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// Structure type Name declaration
struct Name {
	char firstName[31];
	char middleInitial[7];
	char lastName[36];
};

// Structure type Address declaration
struct Address {
	int streetNumber;
	char street[41];
	int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
struct Numbers {
	char cell[11];
	char home[11];
	char business[11];
};

// Structure type Contact declaration
struct Contact {
	struct Name name;
	struct Address address;
	struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

void getName(struct Name *a);
void getAddress(struct Address *a);
void getNumbers(struct Numbers *a);
void displayContact(struct Contact *a);
void getContact(struct Contact *a);

#endif // !CONTACTS_H_
