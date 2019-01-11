// **********************************************************^M
// Workshop 8: Virtual Functions
// SavingsAccount.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#include <iomanip>
#include "SavingsAccount.h"

namespace sict {
	// constructor initializes balance and interest rate
	SavingsAccount::SavingsAccount(double int_rate, double balance) : Account::Account(balance) {
		interest_rate = int_rate > 0 ? int_rate : 0.0;
	}

	// perform month end transactions
	void SavingsAccount::monthEnd() {
		Account::credit(Account::balance() * interest_rate);
	}

	// display inserts the account information into an ostream			
	void SavingsAccount::display(std::ostream& os) const {
		os << "Account type: Savings" << std::endl;
		os.setf(os.fixed, os.floatfield);
		os.precision(2);
		os << "Balance: $" << Account::balance() << std::endl;
		os << "Interest Rate (%): " << interest_rate * 100 << std::endl;
	}
}