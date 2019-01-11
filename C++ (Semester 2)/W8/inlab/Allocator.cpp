// **********************************************************^M
// Workshop 8: Virtual Functions
// Allocator.cpp
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#include "SavingsAccount.h" 
namespace sict {

	// define interest rate
	const double int_rate = 0.05;

	// Allocator function
	iAccount* CreateAccount(const char* type, double balance) {
		iAccount* account = nullptr;
		if (type[0] == 'S') {
			account = new SavingsAccount(int_rate, balance);
		}
		return account;
	}
}