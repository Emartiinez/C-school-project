// Workshop 6 - Class with a Resource
// Contact.cpp
// Fabio Bernal
// 2018/07/7

#define _CRT_SECURE_NO_WARNINGS
#include "Contact.h"
#include <iostream>
#include <cstring>
using namespace std;

namespace sict
{
	void Contact::set()
	{
		empty = false;
		contact_name[0] = char(0);
		phone_number = nullptr;
		num_of_phone = 0;
	}

	void Contact::set(const char* Name, const long long* phoneNumbers, const int& numOfPhones) 
	{
	
		if (Name != nullptr && Name[0] != char(0))
		{
			int name_length = strlen(Name);
			long long* valid_Phones = new long long[numOfPhones];
			int number_Of_Valid_Phones = 0;
			empty = true;
		if (name_length <= MAX_NAME) {
				strncpy(contact_name, Name, name_length);
				contact_name[name_length] = char(0);
			}
			else {

				strncpy(contact_name, Name, MAX_NAME - 2);
				contact_name[MAX_NAME - 2] = char(0);
			}


			for (int i = 0; i < numOfPhones; i++) {
				if (isValid(phoneNumbers[i])) {
					valid_Phones[number_Of_Valid_Phones] = phoneNumbers[i];
					number_Of_Valid_Phones++;
				}
			}


			phone_number = new long long[number_Of_Valid_Phones];
			num_of_phone = number_Of_Valid_Phones;

			for (int i = 0; i < num_of_phone; i++)
			{
				phone_number[i] = valid_Phones[i];
			}

			delete[] valid_Phones;
			valid_Phones = nullptr;
		}

		else 
		{
			set();
		}
	
	}

	Contact::Contact()
	{
		set();
	}

	Contact::Contact(const char* Name, const long long* phoneNumbers, const int& numOfPhones) {
		set(Name, phoneNumbers, numOfPhones);
	}
	Contact::Contact(const Contact& copy)
	{
		empty = copy.empty;
		strncpy(contact_name, copy.contact_name, strlen(copy.contact_name));
		contact_name[strlen(copy.contact_name)] = char(0);

		phone_number = new long long[num_of_phone = copy.num_of_phone];

		for (int i = 0; i < num_of_phone; i++)
		{
			phone_number[i] = copy.phone_number[i];
		}


	}

	Contact::~Contact() 
	{
		delete[] phone_number;
		phone_number = nullptr;
	}

	bool Contact::isEmpty() const 
	{
		return !empty;
	}

	bool Contact::isValid(const long long& Number) const {
		bool temp = false;
		long long phone = Number;
		int digits = 0;
		int* phone_Digits = nullptr;

		if (Number > 0) {

			digits = numOfDigits(Number);

			if (digits == 11 || digits == 12)
			{
				phone_Digits = new int[digits];
				Array(phone_Digits, phone, digits);
				if (phone_Digits[digits - 7] != 0 && phone_Digits[digits - 10] != 0 && (phone_Digits[0] + phone_Digits[digits - 11]) != 0)
				{
					temp = true;
				}
				delete[] phone_Digits;
				phone_Digits = nullptr;
			}
		}
		return temp;
	}

	void Contact::display() const {
		if (isEmpty()) {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << contact_name << endl;

			if (num_of_phone > 0) {
				for (int i = 0; i < num_of_phone; i++)
				{
					int digits = numOfDigits(phone_number[i]);
					int* phone_Digits = new int[digits];
					Array(phone_Digits, phone_number[i], digits);
					if (digits == 11)
					{
						cout << "(+" << phone_Digits[0] << ") ";
						cout << phone_Digits[1] << phone_Digits[2] << phone_Digits[3] << " ";
						cout << phone_Digits[4] << phone_Digits[5] << phone_Digits[6] << "-" << phone_Digits[7] << phone_Digits[8] << phone_Digits[9] << phone_Digits[10] << endl;
					}
					else if (digits == 12)
					{
						cout << "(+" << phone_Digits[0] << phone_Digits[1] << ") ";
						cout << phone_Digits[2] << phone_Digits[3] << phone_Digits[4] << " ";
						cout << phone_Digits[5] << phone_Digits[6] << phone_Digits[7] << "-" << phone_Digits[8] << phone_Digits[9] << phone_Digits[10] << phone_Digits[11] << endl;
					}
					delete[] phone_Digits;
					phone_Digits = nullptr;
				}
			}
		}

	}

	int* Array(int* emptyArray, long long number, const int& numOfDigits) {

		for (int i = numOfDigits - 1; i >= 0; i--) {
			emptyArray[i] = number % 10;
			number /= 10;
		}

		return emptyArray;
	}


	int numOfDigits(long long phone) {
		int result = 0;
	
		while (phone) {
			result++;
			phone /= 10;
		}

		return result;
	}

	Contact& Contact::operator = (const Contact& copy)
	{
		if (!isEmpty() && this != &copy)
		{
			empty = copy.empty;
			strncpy(contact_name, copy.contact_name, strlen(copy.contact_name));
			contact_name[strlen(copy.contact_name)] = char(0);
			phone_number = new long long[num_of_phone = copy.num_of_phone];

			for (int i = 0; i < num_of_phone; i++)
			{
				phone_number[i] = copy.phone_number[i];
			}

		}
		return *this;
	}
	Contact& Contact::operator += (const long long& PhoneNum)
	{
		if (!isEmpty() && isValid(PhoneNum))
		{
			long long* phoneCpy = new long long[num_of_phone];


			for (int i = 0; i < num_of_phone; i++)
			{
				phoneCpy[i] = phone_number[i];
			}
			delete[] phone_number;

			      = new long long[num_of_phone + 1];
			num_of_phone++;

			for (int i = 0; i < num_of_phone -1 ; i++)
			{
				phone_number[i] = phoneCpy[i];
			}
			phone_number[num_of_phone - 1] = PhoneNum;

		}
		return *this;
	}

}




