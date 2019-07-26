// Name: Fabio Bernal
// ID: 036422103

#define _CRT_SECURE_NO_WARNINGS
#include "SavingsAccount.h" 

using namespace std;

namespace sict 
{

	// define interest rate
	//
	const double interest = 0.05;
	
	// TODO: Allocator function
	
	iAccount* CreateAccount(const char* account, double account_balance)
	{
		iAccount *temp = nullptr;
		
		if (account[0] == 'S')
		temp = new SavingsAccount (account_balance, interest);
		return temp;
	}



}
