/* -------------------------------------------

Name: Usman Kazmi	

Student number:128674173

Email: sukazmi@myseneca.ca

Section: Q

Date: March 30 / 2018

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



void getName(struct Name *name)

{

	char a;

	// Contact Name :



	printf("Please enter the contact's first name: ");

	scanf("%s", name->firstName);



	//Storing the answer of this variable in a 

	printf("Do you want to enter a middle initial(s)? (y or n): ");


	scanf(" %c%*c", &a);



	//If condition is true then it will proceed the user to input their middle name

	if (a == 'y' || a == 'Y') {

		printf("Please enter the contact's middle initial(s): ");

		scanf("%s", name->middleInitial);



	}



	printf("Please enter the contact's last name: ");

	scanf("%s", name->lastName);



}







// Get and store from standard input the values for Address

// Put your code here that defines the Contact getAddress function:



void getAddress(struct Address *address)

{
	//Prompting user to enter the required member data for the Address type.
	char a;

	printf("Please enter the contact's street number: ");

	scanf("%d", &address->streetNumber);



	printf("Please enter the contact's street name: ");

	scanf("%s", address->street);

	//Entering the Apartment Number

	printf("Do you want to enter an apartment number? (y or n): ");

	scanf(" %c%*c", &a);

	if (a == 'y' || a == 'Y') {

		printf("Please enter the contact's apartment number: ");

		scanf("%d", &address->apartmentNumber);
	}

	//Since there is a space in between the postal code we have to use %8[^\n] 

	printf("Please enter the contact's postal code: ");

	scanf(" %8[^\n]", address->postalCode);





	printf("Please enter the contact's city: ");

	scanf("%s", address->city);



}







// Get and store from standard input the values for Numbers

// Put your code here that defines the Contact getNumbers function:



void getNumbers(struct Numbers *numbers)

{

	char a; 
	//Prompting the user to enter their cell phone number if they agree then they enter their phone number
	printf("Do you want to enter a cell phone number? (y or n): ");

	scanf(" %c%*c", &a);

	if (a == 'y' || a == 'Y') {

		printf("Please enter the contact's cell phone number: ");

		scanf(" %s", numbers->cell);

	}

	//Prompting the user to enter their home phone number if they agree then they enter the home phone number

	printf("Do you want to enter a home phone number? (y or n): ");

	scanf(" %c%*c", &a);

	if (a == 'y' || a == 'Y') {

		printf("Please enter the contact's home phone number: ");

		scanf(" %s", numbers->home);

	}



	printf("Do you want to enter a business phone number? (y or n): ");

	scanf(" %c%*c", &a);

	if (a == 'y' || a == 'Y') {

		printf("Please enter the contact's business phone number: ");

		scanf(" %s", numbers->business);

	}

}