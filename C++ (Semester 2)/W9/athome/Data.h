/**********************************************************^M
///////////////////////////////////////////////////////////
// Workshop 9: Function Templates
// Data.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/

#pragma once

#include <iostream>
#include <cstring>
using namespace std;

namespace sict {
	// These numbers define 
	// a) the range of data we expect to see in this workshop
	//    0 to 1 billion
	//    use them in the min and max function
	// b) the output column width for a single data field

	const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
	const int SMALLEST_NUMBER = 0;          
	const int COLUMN_WIDTH    = 15;

	// max returns the largest item in data

	template <class T>
	T max(const T* data, int n) {
		T maximum = data[0];
		for (int i = 0; i < n; i++) {
			if (data[i] > maximum) 
				maximum = data[i];
		}
		return maximum;
	}

	// min returns the smallest item in data

	template <class T>
	T min(const T* data, int n) {
		T min = data[0];
		for (int i = 0; i < n; i++) {
			if (data[i] < min) 
				min = data[i];
		}
		return min;
	}
        
	// sum returns the sum of n items in data

	template <class T>
	T sum(const T* data, int n) {
		T sum = 0;
		for (int i = 0; i < n; i++)
			sum += data[i];
		return sum;
	}
   
	// average returns the average of n items in data
	
	template <class T>
	double average(const T* data, int n) {
		return (static_cast<double>(sum(data, n)) / n);
	}

	// read extracts n items from input and stores them in data
	// - the items are comma separated
	// - this function assumes that a comma exists at the next field to be read
	// - for example: ,data1, data2,data3, ...., datan

	template <class T>
	bool read(istream& input, T* data, int n) {
		char seperator;
		bool retVal = true;
		for (int i = 0; i< n; i++) {
			T number;
			input >> seperator;
			if (seperator != ',')
				input.ignore();
			(input >> number) ? data[i] = number : retVal = false;
		}
		return retVal;
	}

	template <class T> // display inserts n items of data into cout
	void display(const char* name, const T* data, int n) {
		cout.width(20);
		cout << right << name;
		for (int i = 0; i < n; i++) {
			cout.width(COLUMN_WIDTH);
			cout << right << data[i];
		}
		cout << endl;
	}

	bool readRow(istream& input, const char* name, int* data, int n);
	bool readRow(istream& input, const char* name, double* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}

