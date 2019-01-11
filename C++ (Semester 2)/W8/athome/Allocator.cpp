// **********************************************************^M
// Workshop 8: Virtual Functions
// Allocator.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#include "SavingsAccount.h" 
#include "ChequingAccount.h"

namespace sict {

	// define rates
	const double int_rate = 0.05;
	const double trans = 0.50;
	const double month_fee = 2.00;
	// Allocator function
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* account = nullptr;
		if (type[0] == 'S') 
			account = new SavingsAccount(int_rate, balance);
		if (type[0] == 'C')
			account = new ChequingAccount(balance, trans, month_fee);
		return account;
	}
}