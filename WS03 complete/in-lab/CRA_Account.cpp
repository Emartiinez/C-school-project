#include<iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {

	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		
		if (sin > min_sin && sin < max_sin)
		{
			strncpy(family_name, familyName,max_name_length);
			strcnpy(account_name, givenName,max_name_length);
			sin_no = sin;
		}
		else
		{
			strcpy(family_name, '\0');
			strcpy(account_name, '\0');
			sin_no = 0;

		}
			
	}

	bool CRA_Account::isEmpty() const
	{
		bool tmp;

		if (family_name == '\0')
			return tmp;
		else
			return tmp;

	}

	void CRA_Account::display() const
	{
		if (family_name != '\0')
		{
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << account_name << endl;
			cout << "CRA Account : " << sin_no << endl;
		}
		else
			cout << "Account object is empty!" << endl;

	}






}