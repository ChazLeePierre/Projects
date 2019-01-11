/*
Name: Chaz Pierre
Student number: 123206179
Email: cpierre4@myseneca.ca
Workshop: 4
Section: SHH
Date: February 13, 2018
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXDAYS 10
int main(void) {

	// declare variables

	int i;
	int initDays;
	int tempHigh = -41, tempLow = 41;
	int dayHigh = -1, dayLow = -1;
	int initMeanNum = 1;
	double dayAvg = 0, totAvg = 0;
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

	/* prompt user for high & low temp values and store those values
	compare temp values with current max/min values and replace if
	temp values are bigger/smaller than current max/min values */

	printf("\n");

	for (i = 0; i < initDays; i++) {
		printf("Day %d - High: ", i + 1);
		scanf("%lf", &arrHigh[i]);
		while (arrHigh[i] > tempHigh) {
			tempHigh = arrHigh[i];
			dayHigh = i + 1;
		}
		printf("Day %d - Low: ", i + 1);
		scanf("%lf", &arrLow[i]);
		while (arrLow[i] < tempLow) {
			tempLow = arrLow[i];
			dayLow = i + 1;
		}
	}

	// output high & low temperature values with the day it occurred

	printf("\nDay  Hi  Low");

	for (i = 0; i < initDays; i++) {
		printf("\n%d    %.0lf    %.0lf", i + 1, arrHigh[i], arrLow[i]);
	}

	printf("\n");

	// output highest/lowest temperature values with the day it occurred

	printf("\nThe highest temperature was %d, on day %d", tempHigh, dayHigh);
	printf("\nThe lowest temperature was %d, on day %d", tempLow, dayLow);

	printf("\n");

	while (initMeanNum > 0) {
		
	// prompt user to enter number & store that value
		
		{
			printf("\nEnter a number between 1 and 4 to see the average temperature for the entered number of days, enter a negative number to exit: ");
			scanf("%d", &initMeanNum);
		}
		
	// ensure value is within the range between 1 to 4

		while (initMeanNum >= 5) {
			printf("\nInvalid entry, please enter a number between 1 and 4, inclusive: ");
			scanf("%d", &initMeanNum);
		} while (initMeanNum < 1) {
			initMeanNum = 0;
			printf("\nGoodbye!\n");
			return 0;

	// calculate total average/mean

		} for (i = 0; i < initMeanNum; i++) {
			dayAvg = (arrHigh[i] + arrLow[i]) / 2.0;
			totAvg += dayAvg;
		}

		totAvg = totAvg / initMeanNum;

	// output total average/mean & equate variables back to zero

		printf("\nThe average temperature up to day %d is: %.2f\n", initMeanNum, totAvg);
		dayAvg = 0;
		totAvg = 0;
	
	// if value is less than zero exit program

	} while (initMeanNum < 1) {
		initMeanNum = 0;
		printf("\nGoodbye!\n");
		return 0;
	}

	return 0;
}