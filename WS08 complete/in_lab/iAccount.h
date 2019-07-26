// Name: Fabio Bernal
// ID: 036422103
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream>

namespace sict {

	class iAccount 
	{
	public:
		// TODO: credit adds +ve amount to the balance
		virtual bool credit(double) = 0;

		// TODO: debit subtracts a +ve amount from the balance
		virtual bool debit(double) = 0;

		// TODO: month end adds month end costs
		virtual void monthEnd() = 0;

		// TODO: display inserts the account information into an ostream
		virtual void display(std::ostream&) const = 0;
		virtual ~iAccount() = 0;
		
	};
	
	// TODO: add prototype for Allocator function
	inline iAccount ::~iAccount() {}
	iAccount* CreateAccount(const char* , double);

}
#endif

