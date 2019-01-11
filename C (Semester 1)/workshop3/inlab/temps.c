/*
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Workshop: 3
Section: SHH
Date: January 6th, 2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 3

int main(void) {
	
	// declare variables

	int i;
	double totHigh = 0, totLow = 0, mean, valHigh, valLow;

	// output title

	printf("---=== IPC Temperature Analyzer ===---");

	// prompt user to enter high & low value for each day and store those values

	for (i = 0; i < NUMS; i++) {
		printf("\nEnter the high value for day %d: ", i + 1);
		scanf("%lf", &valHigh);
		printf("\nEnter the low value for day %d: ", i + 1);
		scanf("%lf", &valLow);

	// if values do not meet requirements (range of -40 to 40 and high must be greater than low) prompt user to re-enter values

	while (valHigh >= 41 || valLow <= -41 || valHigh <= valLow) {
			printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\nEnter the high value for day %d: ", i + 1);
			scanf("%lf", &valHigh);
			printf("\nEnter the low value for day %d: ", i + 1);
			scanf("%lf", &valLow);
		}	

	// each loop add current values to the total variables

		totHigh += valHigh;
		totLow += valLow;
	} 
	
	// calculate and output mean 

	mean = (totHigh + totLow) / (NUMS * 2);
	printf("\nThe average (mean) temperature was: %.2lf\n", mean);

	return 0;
}