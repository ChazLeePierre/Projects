/* -------------------------------------------
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Section: SHH
Date: March 28th 2018
----------------------------------------------
Assignment: 2
Milestone:  4
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS
#define MAXCONTACTS 5 // contact array size

#include <stdio.h>
#include <string.h>
#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// Clear the standard input buffer
void clearKeyboard(void) {
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt function definition goes here:
int getInt(void) {
	char NL = 'x';
	int Value;
	do {
		scanf("%d%c", &Value, &NL);
		if (NL != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (NL != '\n');
	return Value;
}

// getIntInRange function definition goes here:
int getIntInRange(int a, int b) {
	int check = 0, retVal = 0;
	do {
		check = getInt();
		if (check >= a && check <= b) {
			retVal = check;
		}
		else {
			printf("*** INVALID INTEGER *** <Please enter a number between %d and %d>: ", a, b);
		}
	} while (check < a || check > b);
	return retVal;
}

// yes function definition goes here:
int yes(void) {
	char NL = 'x';
	char check = 'x';
	int retVal = -1;
	do {
		scanf(" %c%c", &check, &NL);
		if (NL != '\n' || !(check == 'y' || check == 'Y' || check == 'n' || check == 'N')) {
clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else {
			if (check == 'y' || check == 'Y')
				retVal = 1;
			else if (check == 'n' || check == 'N')
				retVal = 0;
		}
	} while (NL != '\n' || !(check == 'y' || check == 'Y' || check == 'n' || check == 'N'));
	return retVal;
}

// menu function definition goes here:
int menu(void) {
	int option;
	static int x = 0;
	if (x != 0)
		printf("\n");
	x++;
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n");
	printf("\n");
	printf("Select an option:> ");
	option = getIntInRange(0, 6);
	return option;
}

// ContactManagerSystem function definition goes here:
void ContactManagerSystem(void) {
	struct Contact contacts[MAXCONTACTS] =
	{ {	{ "Rick",{ '\0' }, "Grimes" },
			{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
			{ "4161112222", "4162223333", "4163334444" } },
		{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha",{ '\0' }, "Williams" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } },
	};

	int option;
	do {
		option = menu();
		switch (option) {
		case 1:
			displayContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 2:
			addContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 3:
			updateContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 4:
			deleteContact(contacts, MAXCONTACTS);
			pause();
			break;
		case 5:
			searchContacts(contacts, MAXCONTACTS);
			pause();
			break;
		case 6:
			sortContacts(contacts, MAXCONTACTS);
			pause();
			break;
		default:
			printf("\nExit the program? (Y)es/(N)o: ");
			if (yes() == 1) {
				printf("\nContact Management System: terminated\n");
				return;
			}
		}
	} while (option != -1);
}

// getTenDigitPhone:
void getTenDigitPhone(char *telNum)
{
	int needInput = 1;

	while (needInput == 1) {
		scanf("%10s", telNum);
		clearKeyboard();

		// (String Length Function: validate entry of 10 characters)
		if (strlen(telNum) == 10)
			needInput = 0;
		else
			printf("Enter a 10-digit phone number: ");
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) {
	int i;
	int found = -1;
	for (i = 0; i < size - 1; i++) {
		if (strcmp(cellNum, contacts[i].numbers.cell) == 0)
			found = i;
	} 
	return found;
}

// displayContactHeader
void displayContactHeader(void) { // print header
	printf("\n+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter
void displayContactFooter(int number) { // print footer
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", number);
}

// displayContact:
void displayContact(const struct Contact* contact) {
	// Contact Full Name
	if (contact->name.middleInitial[0] == 0) // middle initial checker
		printf(" %s %s\n", contact->name.firstName, contact->name.lastName); 
	else 
		printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
	
	// Contact Numbers
	printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);

	// Contact Address
	printf("       %d %s, ", contact->address.streetNumber, contact->address.street);
	if (contact->address.apartmentNumber > 0) // apartment number checker
		printf("Apt# %d, ", contact->address.apartmentNumber);
	printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}

// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
	int i;
	int valid = 0;
	displayContactHeader();
	for (i = 0; i < size; i++) { // display contact if string is not empty
		if (contacts[i].numbers.cell > 0 && contacts[i].numbers.cell[0] != '\0') {
			displayContact(&contacts[i]);
			valid++;
		}
	}
	displayContactFooter(valid);
}

// searchContacts:
void searchContacts(const struct Contact contact[], int size) {
	char checkCell[11] = { 0 };
	int i, check = 0;
	int found = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(checkCell);
	for (i = 0; i < size - 1; i++) { // check if Contact cell string matches with entered cell string
		if (check == 0) {
			found = findContactIndex(&contact[i], size, checkCell);
			check++;
		}
	} 
	if (found != -1) {
		printf("\n");
		displayContact(&contact[found]);
		printf("\n");
	} else
		printf("\n*** Contact NOT FOUND ***\n");
}

// addContact:
void addContact(struct Contact contact[], int size) {
	int i, index, full = 1;
	for (i = 0; i < size; i++) { // if any Contact cell string equals 0, add contact
		if (strlen(contact[i].numbers.cell) == 0) {
			full--;
			index = i;
		}
	}
	if (full == 0) {
		printf("\n");
		getContact(&contact[index]);
		printf("--- New contact added! ---\n");
	}
	else
		printf("\n*** ERROR: The contact list is full! ***\n");
}

// updateContact:
void updateContact(struct Contact contact[], int size) {
	char checkCell[11] = { 0 };
	int i, check = 0;
	int found = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(checkCell);
	for (i = 0; i < size - 1; i++) { // search for matching cell string
		if (check == 0) {
			found = findContactIndex(&contact[i], size, checkCell);
			check++;
		}
	}
	if (found != -1) { // if contact found, update Contact struct members
		printf("\nContact found:\n");
		displayContact(&contact[found]);
		check = 0;
		printf("\nDo you want to update the name? (y or n): ");
		if (yes() == 1) {
			getName(&contact[found].name);
			check++;
		}
		printf("Do you want to update the address? (y or n): ");
		if (yes() == 1) {
			getAddress(&contact[found].address);
			check++;
		}
		printf("Do you want to update the numbers? (y or n): ");
		if (yes() == 1) {
			getNumbers(&contact[found].numbers);
			check++;
		}
		if (check > 0)
			printf("--- Contact Updated! ---\n");
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}

// deleteContact:
void deleteContact(struct Contact contact[], int size) {
	char checkCell[11] = { 0 };
	int i, check = 0;
	int found = 0;
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(checkCell);
	for (i = 0; i < size - 1; i++) { // search for matching cell string
		if (check == 0) {
			found = findContactIndex(&contact[i], size, checkCell);
			check++;
		}
	}
	if (found != -1) { // if found, assign all members values to zero
		printf("\nContact found:\n");
		displayContact(&contact[found]);
		printf("\nCONFIRM: Delete this contact? (y or n): ");
		if (yes() == 1) {
			contact[found].name.firstName[0] = '\0';
			contact[found].name.middleInitial[0] = '\0';
			contact[found].name.lastName[0] = '\0';
			contact[found].address.streetNumber = 0;
			contact[found].address.street[0] = '\0';
			contact[found].address.apartmentNumber = 0;
			contact[found].address.postalCode[0] = '\0';
			contact[found].address.city[0] = '\0';
			contact[found].numbers.cell[0] = '\0';
			contact[found].numbers.home[0] = '\0';
			contact[found].numbers.business[0] = '\0';
			printf("--- Contact deleted! ---\n");
		}
	}
	else
		printf("*** Contact NOT FOUND ***\n");
}

// sortContacts:
void sortContacts(struct Contact contact[], int size) {
	int i, j;
	struct Contact temp;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (strcmp(contact[j].numbers.cell, contact[j + 1].numbers.cell) > 0) {
				temp = contact[j];
				contact[j] = contact[j + 1];
				contact[j + 1] = temp;
			}

		}

	}
	printf("\n--- Contacts sorted! ---\n");
}
