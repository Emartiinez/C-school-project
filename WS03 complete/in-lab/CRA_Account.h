#ifndef SICT_ACCOUNT_H
#define SICT_ACCOUNT_H

namespace sict {

	const int SICT_ACCOUNT_H;
	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;


	class CRA_Account {
		char family_name [ max_name_length + 1];
		char account_name [max_name_length + 1];
		int sin_no;

	public:
	
		void set(const char* familyName, const char* givenName, int sin);
		bool isEmpty() const;
		void display() const;

};


}





#endif
