// Workshop 5: operator overloading
// File: Fraction.cpp
// Version: 2.0
// Date: 2018/06/19
// Author: Fabio Bernal
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

// TODO: insert header files
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Fraction.h"
using namespace std;


// TODO: continue the namespace
namespace sict
{
	// TODO: implement the default constructor
	Fraction::Fraction()
	{
		fraction_numerator = 0;
		fraction_denominator = 0;


	}

	// TODO: implement the two-argument constructor
	Fraction::Fraction(int numerator, int denominator)
	{

		if (numerator >= 0 && denominator > 0)
		{
			fraction_numerator = numerator;
			fraction_denominator = denominator;
			reduce();

		}
		else
		{
			*this = Fraction();
		}

	}

	// TODO: implement the max query
	int Fraction::max() const
	{
		int temp;
		if (fraction_numerator > fraction_denominator)
		{
			temp = fraction_numerator;
		}
		else
		{
			temp = fraction_denominator;
		}
		return temp; \

	}

	// TODO: implement the min query
	int Fraction::min() const
	{
		int temp;
		if (fraction_numerator < fraction_denominator)
		{
			temp = fraction_numerator;
		}
		else
		{
			temp = fraction_denominator;
		}
		return temp;

	}
	// gcd returns the greatest common divisor of num and denom
	//
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	// TODO: implement the reduce modifier
	void Fraction::reduce()
	{
		int  temp = gcd();
		fraction_numerator /= temp;
		fraction_denominator /= temp;
	}

	// TODO: implement the display query
	void Fraction::display() const
	{
		if (isEmpty() == false && fraction_denominator != 1)
		{
			cout << fraction_numerator << "/" << fraction_denominator;
		}
		else if (isEmpty() == false && fraction_denominator == 1)
		{
			cout << fraction_numerator;
		}

		else if (isEmpty() == true)
		{

			cout << "no fraction stored";
		}
	}

	// TODO: implement the isEmpty query
	bool Fraction::isEmpty() const
	{
		bool ToF;

		if (fraction_numerator <= 0 || fraction_denominator <= 0)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}
	// TODO: implement the + operator
	Fraction Fraction:: operator+(const Fraction& rhs) const
	{
		Fraction Total;

		if (this->isEmpty() == false && rhs.isEmpty() == false)
		{
			Total.fraction_numerator = (this->fraction_numerator *rhs.fraction_denominator) + (this->fraction_denominator * rhs.fraction_numerator);
			Total.fraction_denominator = (this->fraction_denominator * rhs.fraction_denominator);
			Total.reduce();
		}
		else
		{
			Total = Fraction();
		}
		return Total;
	}
	Fraction Fraction::operator * (const Fraction& rhs)
	{
		Fraction Total;
		if (this->isEmpty() == false && rhs.isEmpty() == false)
		{
			Total.fraction_numerator = (fraction_numerator*rhs.fraction_denominator);
			Total.fraction_denominator = (fraction_denominator*rhs.fraction_denominator);
			Total.reduce();
		}
		return Total;
	}

	bool Fraction::operator == (const Fraction& rhs) const 
	{
		bool ToF;

		if (this->isEmpty() == false && rhs.isEmpty() == false)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}
	bool Fraction::operator != (const Fraction& rhs) const
	{
		bool ToF;
		 
		if (this->isEmpty() == false && rhs.isEmpty() == false)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}

	Fraction& Fraction::operator += (const Fraction& rhs)
	{
		Fraction Total;
		if (this->isEmpty() == false && rhs.isEmpty() == false)
		{
			*this = *this + rhs;
		}
		else
		{
			*this = Total;
		}
		return *this;
	}


}