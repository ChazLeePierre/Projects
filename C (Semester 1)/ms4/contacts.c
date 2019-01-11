/* -------------------------------------------
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Section: SHH
Date: March 4th 2018
----------------------------------------------
Assignment: 1
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *a) {
	char check;
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", (*a).firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", (*a).middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", (*a).lastName);
}

// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *a) {
	char check;
	printf("Please enter the contact's street number: ");
	scanf("%d", &(*a).streetNumber);
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", (*a).street);
	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &(*a).apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", (*a).postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", (*a).city);
}

// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *a) {
	char check;
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %[^\n]", (*a).cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %[^\n]", (*a).home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %[^\n]", (*a).business);
	}
}

// Display Contact summary details function
void displayContact(struct Contact *a) {
	printf("\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", (*a).name.firstName);
	if ((*a).name.middleInitial[0] != 0)
		printf("Middle initial(s): %s\n", (*a).name.middleInitial);
	printf("Last name: %s\n", (*a).name.lastName);
	printf("\nAddress Details\n");
	printf("Street number: %d\n", (*a).address.streetNumber);
	printf("Street name: %s\n", (*a).address.street);
	if ((*a).address.apartmentNumber != 0)
		printf("Apartment: %d\n", (*a).address.apartmentNumber);
	printf("Postal code: %s\n", (*a).address.postalCode);
	printf("City: %s\n", (*a).address.city);
	printf("\nPhone Numbers:\n");
	if ((*a).numbers.cell[0] != 0)
		printf("Cell phone number: %s\n", (*a).numbers.cell);
	if ((*a).numbers.home[0] != 0)
		printf("Home phone number: %s\n", (*a).numbers.home);
	if ((*a).numbers.business[0] != 0)
		printf("Business phone number: %s\n", (*a).numbers.business);
}
