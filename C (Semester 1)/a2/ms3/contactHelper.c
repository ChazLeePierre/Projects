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
#include <string.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:
#include "contactHelpers.h"

//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void) {
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void) {
	printf("(Press Enter to continue)");
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
}

// getIntInRange function definition goes here:
int getIntInRange(int a, int b) {
	int check = 0;
	do {
		check = getInt();
		if (check <= a && check >= b) {
			return check;
		}
		else {
			printf("*** INVALID INTEGER *** <Please enter a number between %d and %d>: ", a, b);
		}
	} while (!(check <= a && check >= b));
}

// yes function definition goes here:
int yes(void) {
	char NL = 'x';
	char check = 'x';
	do {
		scanf("%c%c", &check, &NL);
		if (NL != '\n' || !(check == 'y' || check == 'Y' || check == 'n' || check == 'N')) {
			clearKeyboard();
			printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		}
		else {
			if (check == 'y' || check == 'Y')
				return 1;
			else if (check == 'n' || check == 'N')
				return 0;
		}
	} while (NL != '\n' || !(check == 'y' || check == 'Y' || check == 'n' || check == 'N'));
}

// menu function definition goes here:
int menu(void) {
	int option;
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
	int option;
	do {
		option = menu();
		switch (option) {
		case 1:
			printf("<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			break;
		case 2:
			printf("<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			break;
		case 3:
			printf("<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			break;
		case 4:
			printf("<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			break;
		case 5:
			printf("<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			break;
		case 6:
			printf("<<< Feature %d is unavailable >>>\n\n", option);
			pause();
			break;
		default:
			printf("Exit the program? (Y)es/(N)o: ");
			if (yes() == 1) {
				printf("Contact Management System: terminated\n");
				return 0;
			}
		}
	} while (option != 0);
}

void getTenDigitPhone(char telNum[])
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
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    return -1;
}


// displayContactHeader
void displayContactHeader(void) {

}

// displayContactFooter
void displayContactFooter(int) {

}

// displayContact:
void displayContact(const struct Contact*) {

}

// displayContacts:
void displayContacts(const struct Contact[], int) {

}

// searchContacts:
void searchContacts(const struct Contact[], int) {

}

// addContact:
void addContact(struct Contact[], int) {

}

// updateContact:
void updateContact(struct Contact[], int) {

}

// deleteContact:
void deleteContact(struct Contact[], int) {

}

// sortContacts:
void sortContacts(struct Contact[], int) {

}