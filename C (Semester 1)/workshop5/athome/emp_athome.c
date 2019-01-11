/*
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Workshop: 5
Section: SHH
Date: Febrary 20th, 2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define Number of Employees "SIZE" to be 2
#define SIZE 4

// Declare Struct Employee 
struct Employee {
	int ID;
	int age;
	double salary;
};

/* main program */
int main(void) {

	int option = 0;
	int i;
	int checkEmp = 0;
	printf("---=== EMPLOYEE DATA ===---\n");

	/* Declare a struct Employee array "emp" with SIZE
	elements and initialize all elements to zero */
	struct Employee emp[SIZE] = {{0}};

	do {
		// Print the option list
		printf("\n1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");

		// Capture input to option variable
		scanf("%d", &option);
		printf("\n");

		switch (option) {

		case 0:	// Exit the program
			printf("Exiting Employee Data Program. Good Bye!!!\n");
			return 0;
			break;

		case 1: // Display Employee Data
			printf("EMP ID  EMP AGE EMP SALARY\n");
			printf("======  ======= ==========\n");

			// display employee id, age and salary of all employees
			for (i = 0; i < SIZE; i++) {
				if (emp[i].ID && emp[i].age && emp[i].salary > 0)
					printf("%6d%9d%11.2lf\n", emp[i].ID, emp[i].age, emp[i].salary);
			}
			break;

		case 2:	// Adding Employee
			printf("Adding Employee\n");
			printf("===============\n");

			// check if maximum amount of employees has been reached
			if (checkEmp >= SIZE)
				printf("ERROR!!! Maximum Number of Employees Reached\n");

			// prompt user to enter employee ID/age/salary and store those values
			if (checkEmp < SIZE) {
				printf("Enter Employee ID: ");
				scanf("%d", &emp[checkEmp].ID);
				printf("Enter Employee Age: ");
				scanf("%d", &emp[checkEmp].age);
				printf("Enter Employee Salary: ");
				scanf("%11lf", &emp[checkEmp].salary);
				checkEmp++;
			}
			break;

		case 3: // Update Employee Salary
			printf("Update Employee Salary\n");
			printf("======================\n");

			int checkID;
			int IDFound = 0;

			/* prompt user to enter employee ID / check if ID exists
			if ID exists replace current salary with new salary the user enters*/
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &checkID);
				for (i = 0; i < SIZE; i++) {
					if (checkID == emp[i].ID) {
						printf("The current salary is %.2lf", emp[i].salary);
						printf("\nEnter Employee New Salary: ");
						scanf("%lf", &emp[i].salary);
						IDFound = 1;
					}
				}
				break;

			// if ID is not found abort case
			} while (IDFound == 0);
				break;

		case 4: // Remove Employee
			printf("Remove Employee\n");
			printf("===============\n");

			IDFound = 0;

			/* prompt user to enter employee ID / check if ID exists
			if ID exists replace current salary with new salary the user enters*/
			do {
				printf("Enter Employee ID: ");
				scanf("%d", &checkID);
				for (i = 0; i < SIZE; i++) {
					if (emp[i].ID == checkID) {
						printf("Employee %d will be removed\n", emp[i].ID);
						emp[i].ID = 0;
						emp[i].salary = 0;
						emp[i].age = 0;
						checkEmp--;
						IDFound = 1;
					}
				}

			// if ID is not found abort case
			} while (IDFound == 0);
				break;

		default: // default option if user enters wrong number
			printf("ERROR: Incorrect Option: Try Again\n");
	}

} while (option != 0); // if user enters 0 return control to OS


return 0;
}



//PROGRAM OUTPUT IS SHOW BELOW

/*
---=== EMPLOYEE DATA ===---

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 111
Enter Employee Age: 34
Enter Employee Salary: 78980.88

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
Enter Employee ID: 112
Enter Employee Age: 41
Enter Employee Salary: 65000

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 2

Adding Employee
===============
ERROR!!! Maximum Number of Employees Reached

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 1

EMP ID  EMP AGE EMP SALARY
======  ======= ==========
111       34   78980.88
112       41   65000.00

1. Display Employee Information
2. Add Employee
0. Exit

Please select from the above options: 0

Exiting Employee Data Program. Good Bye!!!

*/
