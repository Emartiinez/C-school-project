#include<iostream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include "CRA_Account.h"
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

namespace sict {

CRA_Account::CRA_Account()
	{
		family_name[0] = '\0';
		account_name[0] = '\0';
		sin_no = 0;
		*m_years = 0;
		*m_balanceOwed = 0;
		year_num = 0;
	}


	void CRA_Account::set(const char* familyName, const char* givenName, int sin)
	{
		int total = 0;
		int first_set[4] = { (((sin / 10) % 10) * 2), (((sin / 1000) % 10) * 2), (((sin / 100000) % 10) * 2), (((sin / 10000000) % 10) * 2) };
		int second_set[4] = { (((sin / 100) % 10)), (((sin / 10000) % 10)), (((sin / 1000000) % 10)), (((sin / 100000000) % 10)) };
		int GreaterTen = 0;
		bool ToF;

		for (int i = 0; i < 4; i++)
		{
			total += ((((first_set[i] / 1) % 10) + ((first_set[i] / 10) % 10)));
			total += second_set[i];
		}
		GreaterTen = ((total + 9) / 10) * 10;
		if (((GreaterTen - total) == (sin / 1) % 10) && sin >= min_sin && sin <= max_sin)
		{
			ToF = true;
		}
		else
		{
			ToF = false;

		}

		if (ToF == true && "\0" != familyName && "\0" != givenName)
		{
			strncpy(family_name, familyName, max_name_length);
			strncpy(account_name, givenName, max_name_length);
			sin_no = sin;
			
		}
		else
		{
			family_name[0] = '\0';
			account_name[0] = '\0';
			sin_no = 0;
			
		}


	}

	bool CRA_Account::isEmpty() const
	{
		bool ToF;
		cout << "Share Me"<<share_me << endl;
		if (sin_no >= max_sin || sin_no <= min_sin || strlen(family_name)==0|| strlen(account_name) == 0)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}

	void CRA_Account::display() const
	{

		if (sin_no != 0 || family_name != "\0" || account_name != "\0")
		{
			int t = 0;
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << account_name << endl;
			cout << "CRA Account : " << sin_no << endl;
			while (t < max_yrs)
			{
				if (m_balanceOwed[t] > 2)
				{

					cout << "Year(" << m_years[t] << ") balance owing: " << m_balanceOwed[t] << endl;
					t++;
				}
				else
					if (-(m_balanceOwed[t]) > 2)
					{
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "Year(" << m_years[t] << ") refund due: " << -(m_balanceOwed[t]) << endl;
						t++;
					}
					else
					{
						cout.setf(ios::fixed);
						cout.precision(2);
						cout << "Year(" << m_years[t] << ") No balance owing or refund due!" << endl;
						t++;

					}

			}
		}
		else
			cout << "Account object is empty!" << endl;
	}


	void CRA_Account::set(int year, double balance)
	{

		if (sin_no && year_num < max_yrs)
		{

			m_years[year_num] = year;
			m_balanceOwed[year_num] = balance;
			year_num++;
		}
		else
		{
			m_years[year_num] = 0;
			m_balanceOwed[year_num] = 0;
			year_num = 0;

		}
	}
}
//
//
//
//
//
//
//
//
//
//
