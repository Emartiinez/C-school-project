#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_CONTACT_H
#define SICT_CONTACT_H

// Workshop 6 - Class with a Resource
// Contact.h
// Fabio Bernal
// 2018/07/7

namespace sict {


	const int MAX_NAME = 21; 

							  
	class Contact {
	private:
		bool empty; 
		char contact_name[MAX_NAME];
		long long* phone_number;
		int num_of_phone;

		void set(); 
		void set(const char* contactName, const long long* phoneNumber, const int& numberOfPhones);
		bool isValid(const long long& phoneNumber) const;
	public:
		Contact(); 
		Contact(const char* contactName, const long long* phoneNumber, const int& numberOfPhones);
		Contact(const Contact& copy); // home
		~Contact();
		bool isEmpty() const;
		void display() const;
		Contact& operator = (const Contact& copy); // home 
		Contact& operator += (const long long& PhoneNum);// home 

	};
	int* Array(int* emptyArray, long long number, const int& numberOfDigits);
	int numOfDigits(long long phone);








	

}
#endif 





/*const int MAX_NAME = 21;

class Contact
{
	char Contact_Name[MAX_NAME];
	long long * Phone_Number;
	int Number_of_phones;
	bool empty;



public:

	Contact();
	Contact(const char* Name, const long long* Number, const int& Num_Of_Phones);
	~Contact();

	bool isEmpty()const;
	void display()const;
	bool Valid(const long long& phoneNumber) const;


};

int Num_of_Digits(long long Number)*/;