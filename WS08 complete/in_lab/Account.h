// Name: Fabio Bernal
// ID: 036422103

#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
#include "iAccount.h"

namespace sict 
{
   
	class Account : public iAccount
	{
	double Account_Balance;
	
	protected:
		double balance()const;
	public:
		
		Account(double bal);
		bool credit(double add);
		bool debit(double subtract);

		
	};


}
#endif
