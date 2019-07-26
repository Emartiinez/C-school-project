// Name: Fabio Bernal
// ID: 036422103
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include <iostream>
#include "Account.h"

namespace sict 
{
	class SavingsAccount : public Account
	{
		double account_interest;
	
	public:
			// TODO: constructor initializes balance and interest rate
		SavingsAccount(double bal, double Int_rate);

			// TODO: perform month end transactions
		void monthEnd();

			// TODO: display inserts the account information into an ostream			
		void display(std::ostream& ostr) const;
	};
}
#endif
