// Name: Fabio Bernal
// ID: 036422103

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;

namespace sict
{
	Account::Account(double bal)
	{
	
		if (bal > 0)
		{
			Account_Balance = bal;
		}
		else 
		{
			Account_Balance = 0;
		}
	
	}

	bool Account :: credit(double add)
	{
		bool TOF;
		if (add > 0)
		{
			Account_Balance += add;
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}

	bool Account::debit(double subtract)
	{
		bool TOF;
		if (subtract > 0)
		{
			Account_Balance -= subtract;
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}
	double Account::balance() const
	{
		return Account_Balance;
	}





}