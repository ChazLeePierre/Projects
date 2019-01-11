/* -------------------------------------------
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Section: SHH
Date: March 4th 2018
----------------------------------------------
Assignment: 1
Milestone:  2
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name contactName = {{0}};
	struct Address contactAddress = { 0, {0}};
	struct Numbers contactNumbers = {{0}};
	char check;

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]", contactName.firstName);
	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]", contactName.middleInitial);
	}
	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]", contactName.lastName);

	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &contactAddress.streetNumber);
	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]", contactAddress.street);
	printf("Do you want to enter an appartment number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's appartment number: ");
		scanf("%d", &contactAddress.apartmentNumber);
	}
	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]", contactAddress.postalCode);
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]", contactAddress.city);

	// Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's cell phone number: ");
		scanf(" %[^\n]", contactNumbers.cell);
	}
	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's home phone number: ");
		scanf(" %[^\n]", contactNumbers.home);
	}
	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &check);
	if (check == 'y' || check == 'Y') {
		printf("Please enter the contact's business phone number: ");
		scanf(" %[^\n]", contactNumbers.business);
	}

	// Display Contact Summary Details
	printf("\nContact Details\n");
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", contactName.firstName);
	if (contactName.middleInitial[0] != 0)
		printf("Middle initial(s): %s\n", contactName.middleInitial);
	printf("Last name: %s\n", contactName.lastName);
	printf("\nAddress Details\n");
	printf("Street number: %d\n", contactAddress.streetNumber);
	printf("Street name: %s\n", contactAddress.street);
	if (contactAddress.apartmentNumber != 0)
		printf("Apartment: %d\n", contactAddress.apartmentNumber);
	printf("Postal code: %s\n", contactAddress.postalCode);
	printf("City: %s\n", contactAddress.city);
	printf("\nPhone Numbers:\n");
	if (contactNumbers.cell[0] != 0)
		printf("Cell phone number: %s\n", contactNumbers.cell);
	if (contactNumbers.home[0] != 0)
		printf("Home phone number: %s\n", contactNumbers.home);
	if (contactNumbers.business[0] != 0)
		printf("Business phone number: %s\n", contactNumbers.business);

	// Display Completion Message
	printf("\nStructure test for Name, Address, and Numbers Done!\n");

	return 0;
}

/*  SAMPLE OUTPUT:

Contact Management System
-------------------------
Please enter the contact's first name: Tom
Do you want to enter a middle initial(s)? (y or n): y
Please enter the contact's middle initial(s): Wong
Please enter the contact's last name: Song
Please enter the contact's street number: 20
Please enter the contact's street name: Keele
Do you want to enter an appartment number? (y or n): y
Please enter the contact's appartment number: 40
Please enter the contact's postal code: A8A 4J4
Please enter the contact's city: Toronto
Do you want to enter a cell phone number? (y or n): Y
Please enter the contact's cell phone number: 905-111-6666
Do you want to enter a home phone number? (y or n): Y
Please enter the contact's home phone number: 705-222-7777
Do you want to enter a business phone number? (y or n): Y
Please enter the contact's business phone number: 416-333-8888
Contact Details
---------------
Name Details
First name: Tom
Middle initial(s): Wong
Last name: Song
Address Details
Street number: 20
Street name: Keele
Apartment: 40
Postal code: A8A 4J4
City: Toronto
Phone Numbers:
Cell phone number: 905-111-6666
Home phone number: 705-222-7777
Business phone number: 416-333-8888
Structure test for Name, Address, and Numbers Done!
*/
