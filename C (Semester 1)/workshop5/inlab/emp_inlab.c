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
#define SIZE 2

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
			for (i = 0; i < checkEmp; i++) {
					if (emp[i].ID && emp[i].age && emp[i].salary > 0){
						printf("%6d%9d%11.2lf\n", emp[i].ID, emp[i].age, emp[i].salary);
					}
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
		default: // default option if user enters wrong number
			printf("ERROR: Incorrect Option: Try Again\n\n");
		}

	} while (option != 0);


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
