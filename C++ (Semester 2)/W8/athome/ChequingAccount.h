// **********************************************************^M
// Workshop 8: Virtual Functions
// ChequingAccount.h
// Name: Chaz Pierre
// Email: cpierre4@myseneca.ca
// Student#: 123206179
// ///////////////////////////////////////////////////////////
// **********************************************************/
#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict {
	class ChequingAccount : public Account {
		double trans_fee;
		double month_end_fee;

		public:
			ChequingAccount(double balance, double trans, double month_end); // constructor initializes account balance and transaction fee
			bool credit(double amount); // credit adds +ve amount to the balance
			bool debit(double amount); // debit subtracts a +ve amount from the balance
			void monthEnd(); // month end
			void display(std::ostream&) const; // display inserts the account information into an ostream
			~ChequingAccount() {};
	};
}
#endif
