// **********************************************************^M
// Workshop 8: Virtual Functions
// Account.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"

namespace sict {
	class Account : public iAccount {
		double acc_balance;
	protected:
		double balance() const;
	public:
		Account();
		Account(double); // constructor initializes account balance, defaults to 0.0 
		bool credit(double); // credit adds +ve amount to the balance 
		bool debit(double); // debit subtracts a +ve amount from the balance
	};
}
#endif
