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



#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"

// getName:
void getName(struct Name *a) {
	char check;
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", (*a).firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	check = yes();
	if (check == 1) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", (*a).middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", (*a).lastName);
}

// getAddress:
void getAddress(struct Address *a) {
	char check;
	printf("Please enter the contact's street number: ");
	scanf("%d", &(*a).streetNumber);
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", (*a).street);
	printf("Do you want to enter an apartment number? (y or n): ");
	check = yes();
	if (check == 1) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &(*a).apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", (*a).postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", (*a).city);
}

// getNumbers:
void getNumbers(struct Numbers *a) {
	char check;
	printf("Please enter the contact's cell phone number: ");
	getTenDigitPhone(a->cell);
	printf("Do you want to enter a home phone number? (y or n): ");
	check = yes();
	if (check == 1) {
		printf("Please enter the contact's home phone number: ");
		getTenDigitPhone(a->home);
	}
	else
		*a->home = '\0';
	printf("Do you want to enter a business phone number? (y or n): ");
	check = yes();
	if (check == 1) {
		printf("Please enter the contact's business phone number: ");
		getTenDigitPhone(a->business);
	}
	else
		*a->business = '\0';
}

// displayContact:
void printContact(struct Contact *a) {
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
	printf("\nPhone numbers:\n");
	if ((*a).numbers.cell[0] != 0)
		printf("Cell phone number: %s\n", (*a).numbers.cell);
	if ((*a).numbers.home[0] != 0)
		printf("Home phone number: %s\n", (*a).numbers.home);
	if ((*a).numbers.business[0] != 0)
		printf("Business phone number: %s\n", (*a).numbers.business);
}

// getContact
void getContact(struct Contact *a) {
	getName(&a->name);
	getAddress(&a->address);
	getNumbers(&a->numbers);
}