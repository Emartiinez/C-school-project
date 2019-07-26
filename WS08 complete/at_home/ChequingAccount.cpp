// Name: Fabio Bernal
// ID: 036422103
#include <iostream>
#include "ChequingAccount.h"

using namespace std;

namespace sict 
{
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double bal, double trans_fee, double mon_fee) : Account(bal)
	{

		if (trans_fee > 0 && mon_fee > 0)
		{
			transaction_fee = trans_fee;
			month_fee = mon_fee;

		}
		else
		{
			transaction_fee = 0;
			month_fee = 0;
		}
	}

	// credit (add) an amount to the account balance and charge fee
	// returns bool indicating whether money was credited
	//
	bool ChequingAccount::credit(double add)
	{
		bool TOF;

		if (Account::credit(add))
		{
			Account::debit(transaction_fee);
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//

	bool ChequingAccount::debit(double subtract)
	{
		bool TOF;

		if (Account::debit(subtract + transaction_fee))
		{
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}

	// monthEnd debits month end fee
	//

	void ChequingAccount::monthEnd()
	{
		Account::debit(month_fee + transaction_fee);
	}

	// display inserts account information into ostream os
	//

	void ChequingAccount::display(ostream& ostr) const
	{
		ostr << "Account type: Chequing" << endl;
		ostr.precision(2);
		ostr.setf(ios::fixed);
		ostr << "Balance: $" << Account::balance() << endl;
		ostr << "Per Transaction Fee: " << transaction_fee << endl;
		ostr << "Monthly Fee: " << month_fee << endl;
	
	}


}