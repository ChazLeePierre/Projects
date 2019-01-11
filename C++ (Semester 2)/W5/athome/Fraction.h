/**********************************************************
///////////////////////////////////////////////////////////
// Workshop 5: Operator Overloading
// Fraction.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/
#pragma once
namespace sict {
	class Fraction {
		int f_num; // numerator
		int f_deno; // denominator
		int max() const; // return greater of numerator and denominator
		int min() const; // return lesser of numerator and denominator
		void reduce(); // reduce fraction to its lowest denominator
		int gcd() const; // return greatest common denominator
	public: 
 		Fraction(); // safe empty state (constructor)
		Fraction(int num, int denom); // set numerator and denominator if data is valid
		bool isEmpty() const; // check if in safe empty state
	 	void display() const;  // display formatted data
	 	Fraction operator+(const Fraction& rhs) const; // overload plus operator to add two Fractions
	 	Fraction operator*(const Fraction& rhs) const; // overload multiply operator to multiply two Fractions
	 	bool operator==(const Fraction& rhs) const; // overload equality operator to check for equality of two Fractions
	 	bool operator!=(const Fraction& rhs) const; // overload not equality operator to check for equality of two Fractions
	 	Fraction& operator+=(const Fraction& rhs); // overload plus equal operator to add a Fraction to an existing Fraction
	};
}
