// Name: Fabio Bernal
// ID: 036422103

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "SavingsAccount.h"
using namespace std;

namespace sict
{
	SavingsAccount::SavingsAccount(double bal, double Int_rate) : Account(bal)
	{
		if (Int_rate >= 0)
		{
			account_interest = Int_rate;
		}
		else
		{
			account_interest = 0;
		}
	}

	void SavingsAccount::monthEnd()
	{
		double accnt_int;
		accnt_int = (balance() * account_interest);
		credit(accnt_int);
	
	}

	void SavingsAccount::display(ostream& ostr) const
	{
		ostr << "Account Type: Savings" << endl;
		ostr.precision(2);
		ostr.setf(ios::fixed); 
		ostr <<"Balance: $"<< balance() << endl;
		ostr << "Interest Rate (%): " << (account_interest * 100) << endl;
		ostr.precision(6);
		ostr.unsetf(ios::fixed);
	}






}

