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
	
	double initAmount;
	int oweAmount, valCoin;
	
	// prompt user to enter the amount paid and return loonies required / balance owing 

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &initAmount);
	valCoin = (int)initAmount;
	initAmount = initAmount * 100;
	oweAmount = initAmount;
	oweAmount = oweAmount % 100;
	printf("Loonies required: %d, balance owing $%.2lf\n", valCoin, oweAmount / 100.0);

	// return quarters required / balance owing

	valCoin = oweAmount / 25;
	oweAmount = oweAmount % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", valCoin, oweAmount / 100.0);
	return 0;
}
