// **********************************************************^M
// Workshop 8: Virtual Functions
// Account.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#include "Account.h"

namespace sict {

	double Account::balance() const {
		return acc_balance;
	}

	// constructor initializes account balance, defaults to 0.0 
	Account::Account(double balance = 0.0) {
		acc_balance = balance > 0 ? balance : 0.0;
	}

	// credit adds +ve amount to the balance 
	bool Account::credit(double balance) {
		if (balance > 0) 
			acc_balance += balance;
		return balance > 0 ? true : false;
	}

	// debit subtracts a +ve amount from the balance
	bool Account::debit(double balance) {
		if (balance > 0) 
			acc_balance -= balance;
		return balance > 0 ? true : false;
	}
}