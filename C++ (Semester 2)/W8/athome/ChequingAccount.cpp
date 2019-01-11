// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

// **********************************************************^M
// Workshop 8: Virtual Functions
// ChequingAccount.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	ChequingAccount::ChequingAccount(double balance, double trans, double month_end) : Account(balance) {
		trans_fee = trans > 0 ? trans : 0.0;
		month_end_fee = month_end > 0 ? month_end : 0.0;
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	bool ChequingAccount::credit(double balance) {
		if (Account::credit(balance)) {
			Account::debit(trans_fee);
			return true;
		} else return false;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	bool ChequingAccount::debit(double balance) {
		if (Account::debit(balance)) {
			Account::debit(trans_fee);
			return true;
		} else return false;
	}

	// monthEnd debits month end fee
	void ChequingAccount::monthEnd() {
		debit(month_end_fee);
	}

	// display inserts account information into ostream os
	void ChequingAccount::display(std::ostream& os) const {
		os << "Account type: Chequing" << std::endl;
		os.setf(os.fixed, os.floatfield);
		os.precision(2);
		os << "Balance: $" << Account::balance() << std::endl;
		os << "Per Transaction Fee: " << trans_fee << std::endl;
		os << "Monthly Fee: " << month_end_fee << std::endl;
	}
}