/*
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Workshop: 4
Section: SHH
Date: February 13th 2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXDAYS 10

int main(void) {

	// declare variables

	int i;
	int initDays;
	double arrHigh[MAXDAYS] = { 0 }, arrLow[MAXDAYS] = { 0 };

	// output title

	printf("---=== IPC Temperature Calculator V2.0 ===---");

	// prompt user for # of days and store that value

	printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &initDays);
	
	// if values do not meet requirements (range of 3 days to 10 days) prompt user to re-enter value

	while (3 > initDays || initDays > 10) {
		printf("\nInvalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d)", &initDays);
	}
	
	// prompt user for high & low temperature values and store those values
	
	printf("\n");

	for (i = 0; i < initDays; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%lf", &arrHigh[i]);
		printf("Day %d - Low: ", i + 1);
		scanf("%lf", &arrLow[i]);
	}

	// output high & low temperature values with the day it occurred

	printf("\nDay  Hi  Low");

	for (i = 0; i < initDays; i++) {
		printf("\n%d    %.0lf    %.0lf", i + 1, arrHigh[i], arrLow[i]);
	}

	printf("\n");

	return 0;
}