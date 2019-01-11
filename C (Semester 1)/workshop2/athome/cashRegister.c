/*
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Workshop: 1
Section: SHH
Date: January 30th, 2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	// declare variables

	double initAmount, GST;
	int oweAmount, valCoin;

	// prompt user to enter the amount paid 

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &initAmount);

	// calculate GST and add to the initial amount

	GST = initAmount * .13 + .005;
	initAmount += GST;
	printf("GST: %.2lf\n", GST);
	printf("Balance owing: $%.2lf\n", initAmount);

	// return loonies required / balance owing
	
	valCoin = (int)initAmount;
	initAmount = initAmount * 100;
	oweAmount = initAmount;
	oweAmount = oweAmount % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", valCoin, (double)oweAmount / 100);

	// return quarters required / balance owing

	valCoin = oweAmount / 25;
	oweAmount = oweAmount % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", valCoin, (double)oweAmount / 100);

	// return dimes required / balance owing

	valCoin = oweAmount / 10;
	oweAmount = oweAmount % 10;
	printf("Dimes required: %d, balance owing $%.2lf\n", valCoin, (double)oweAmount / 100);

	// return nickels required / balance owing

	valCoin = oweAmount / 5;
	oweAmount = oweAmount % 5;
	printf("Nickels required: %d, balance owing $%.2lf\n", valCoin, (double)oweAmount / 100);

	// return pennies required / balance owing

	valCoin = oweAmount / 1;
	oweAmount = oweAmount % 1;
	printf("Pennies required: %d, balance owing $%.2lf\n", valCoin, (double)oweAmount / 100);
	
	return 0;
}
