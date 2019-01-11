// **********************************************************^M
// Workshop 8: Virtual Functions
// SavingsAccount.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"

namespace sict {
	class SavingsAccount : public Account {
		double interest_rate;

	public:
		SavingsAccount(double, double); // constructor initializes balance and interest rate
		void monthEnd(); // perform month end transactions	
		void display(std::ostream&) const; // display inserts the account information into an ostream
	};
}
#endif