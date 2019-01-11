/*
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Workshop: 3
Section: SHH
Date: Febuary 6th, 2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUMS 4

int main(void) {

	// declare variables

	int i, dayHigh, dayLow;
	double totHigh = 0, totLow = 0, mean, tempHigh = -41, tempLow = 41, valHigh, valLow;

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

	// compare current values to highest/lowest temp & what day it occurred

		while (valHigh > tempHigh) {
			tempHigh = valHigh;
			dayHigh = i + 1;
		} while (valLow < tempLow) {
			tempLow = valLow;
			dayLow = i + 1;
		}

	// each loop add current values to the total variables

		totHigh += valHigh;
		totLow += valLow;
	}

	// calculate and output mean 

	mean = (totHigh + totLow) / (NUMS * 2);
	printf("\nThe average (mean) temperature was: %.2lf", mean);

	// output highest/lowest temperature

	printf("\nThe highest temperature was %.0lf, on day %d", tempHigh, dayHigh);
	printf("\nThe lowest temperature was %.0lf, on day %d\n", tempLow, dayLow);

	return 0;
}