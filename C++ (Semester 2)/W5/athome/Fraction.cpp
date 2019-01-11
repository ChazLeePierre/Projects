/**********************************************************
///////////////////////////////////////////////////////////
// Workshop 5: Operator Overloading
// Fraction.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
///////////////////////////////////////////////////////////
**********************************************************/
#include <iostream>
#include "Fraction.h"
using namespace std;

namespace sict {

	Fraction::Fraction() { // set to safe empty state
		f_num = -1;
		f_deno = -1;
	}

	Fraction::Fraction(int nume, int deno) { // set class object variables if data is valid else set to safe empty state
	if (nume >= 0 && deno > 0) {
		f_num = nume;
		f_deno = deno;
		reduce();
	} else
		*this = Fraction();
	}
	
	int Fraction::max() const { // return greater value of numerator and denominator
		return (f_num >= f_deno) ? f_num : f_deno;
	}
	
	int Fraction::min() const { // return lesser value of numerator and denominator
		return (f_num <= f_deno) ? f_num : f_deno; 
	}

   	int Fraction::gcd() const { // return greater common denominator
        	int mn = min();  // min of numerator and denominator
        	int mx = max();  // max of numerator and denominator
        	int g_c_d = 1;
        	bool found = false;

        	for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
        	    if (mx % x == 0 && mn % x == 0) {
			found = true;
                	g_c_d = x;
            	    }
        	}
        return g_c_d;
	}
	
	void Fraction::reduce() { // reduce fraction to lowest denominator
		int rGCD = gcd();
		f_num /= rGCD;
		f_deno /= rGCD;
	}
	
	void Fraction::display() const{ // display fraction info
		if (f_deno == 1) // if whole number, omit denominator
			cout << f_num; 
		else if (isEmpty()) // if empty dont display
			cout << "no fraction stored";	
 		else // display if data is valid
			cout << f_num << "/" << f_deno; 
	} 

	bool Fraction::isEmpty() const { // check if safe empty state
		return (f_num == -1 && f_deno == -1) ? true : false;
	}
	
	Fraction Fraction::operator+(const Fraction& rhs) const { // overload plus operator to add two Fraction classes without the use of unneccessary function
		if (isEmpty() || rhs.isEmpty()) // if either Fraction is empty, return empty Fraction
			return Fraction();
		else {	// if data is valid
			int numerator = (f_num * rhs.f_deno) + (rhs.f_num * f_deno); // multiply numerator with opposite denominator, add two results together
			int denominator = f_deno * rhs.f_deno; // multiple both denominators together
			Fraction total = Fraction(numerator, denominator); // set fraction
			total.reduce(); // reduce new fraction to its lowest denominator
			return total;
		}
	}
	
	Fraction Fraction::operator*(const Fraction& rhs) const { // overload multiply operator to multiply two Fraction classes without the use of unneccessary function
		if (isEmpty() || rhs.isEmpty()) // if either Fraction is empty, return empty Fraction
			return Fraction();
		else {	// if data is valid
			int numerator = f_num * rhs.f_num; // multiply both numerators together
			int denominator = f_deno * rhs.f_deno; // multiple both denominators together
			Fraction total = Fraction(numerator, denominator); // set fraction
			total.reduce(); // reduce new fraction to its lowest denominator
			return total;
		}
	}

	bool Fraction::operator==(const Fraction& rhs) const { // overload equality operator to check for equality between two Fraction classes without the use of unneccessary function
		if (isEmpty() || rhs.isEmpty()) // if either Fraction is empty, return false
			return false;
		else 	// if data is valid
			return ( f_num == rhs.f_num && f_deno == rhs.f_deno ) ? true : false; // if numerator and denominator of both Fractions are equal, return true. Otherwise return false.
		
	}

	bool Fraction::operator!=(const Fraction& rhs) const { // overload not equality operator to check for equality between two Fraction classes without the use of unneccessary function
		if (isEmpty() || rhs.isEmpty()) // if either Fraction is empty, return false
			return false;
		else // if data is valid
			return (!(*this == rhs)); // uses logic from overloaded == operator
	}
	
	Fraction& Fraction::operator+=(const Fraction& rhs) { // overload plus equal operator to add a Fraction class to an existing Fraction class without the use of unneccessary function
				this->f_num = -1;
				this->f_deno = -1;
			} else 
				*this = *this + rhs; // uses logic from overloaded + operator
			return *this;
	}

}
