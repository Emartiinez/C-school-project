#define _CRT_SECURE_NO_WARNINGS

#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

namespace sict {

	
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
	const int max_yrs = 4;


	class CRA_Account {
		char family_name [ max_name_length + 1];
		char account_name [max_name_length + 1];
		int sin_no;
		int year_num = 0;
		int m_years[max_yrs];
		double m_balanceOwed[max_yrs];
		

	public:
	
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;
		void set(int year, double balance);
		CRA_Account();
	
		
		
};


}


#endif
