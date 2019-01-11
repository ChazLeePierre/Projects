/* -------------------------------------------
Name: Usman Kazmi

Student number: 128674173

Email:sukazmi@myseneca.ca

Section: Q

Date: March 30 / 2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

// Structure type Name declaration (Milestone 1)
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// Structure type Address declaration 
// Place your code here... (from Milestone 1)
struct Address {
	unsigned int streetNumber;
	char street[41];
	unsigned int apartmentNumber;
	char postalCode[8];
	char city[41];
};

// Structure type Numbers declaration
// Place your code here... (from Milestone 1)
struct Numbers {
	char home[21];
	char cell[21];
	char business[21];
};

// Structure type Contact declaration
// Place your code here... (from Milestone 3)
struct Contacts {
	struct Name name;
	struct Address address;
	struct Numbers number;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======

// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *);

// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *);
