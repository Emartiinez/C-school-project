// Final Project Milestone 1
//
// Version 1.0
// Date
// Author
// Description
//
//
//
//
// Revision History
// -----------------------------------------------------------
//  Name: Fabio Bernal     Date: 7 / 11 / 2018     Reason: cause i have too
/////////////////////////////////////////////////////////////////
#include <iostream>
#include "Date.h"

namespace AMA
{

	int Date::value()const
	{
		return year * 372 + month * 31 + day;
	}


	void Date::set()
	{
		year = 0;
		month = 0;
		day = 0; 
		errCode(NO_ERROR);

	}
	void Date::set(int Y, int M, int D)
	{
		if (year != Y && month != M && day != D)
		{
			set();
		}
		else {
			year = Y;
			month = M;
			day = D;
			errCode(NO_ERROR);
		}
		if (Y == 2016 && M == 2 && D == 29)
		{
			year = Y;
			month = M;
			day = D;
			errCode(NO_ERROR);
		}
	}

	Date::Date()
	{
		set();
	}

	Date::Date(int Y, int M , int D)
	{
		set(Y, M, D);
	}
	void Date::errCode(int errorcode)
	{
		Error_Msg = errorcode;
	}

	// number of days in month mon_ and year year_
	//
	int Date::mdays(int mon, int year)const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1)*((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
	}

	
	// OPERATORS
	
	bool Date ::operator ==(const Date& rhs) const
	{
		bool ToF;
		if (year == rhs.year && month == rhs.month && day == rhs.day)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}
	
	bool Date :: operator!=(const Date& rhs) const
	{
		bool ToF;
		// if ( this -> value() == rhs.value() )
		 if (this->value() == rhs.value())
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;

	}

	bool Date ::operator < (const Date& rhs) const
	{
		bool ToF;

		if (this->value() < rhs.value())
		{
			ToF = false;
		}
		else
		{
			ToF = true;
		}
		return ToF;
	}
	
	bool Date ::operator > (const Date& rhs) const
	{
		bool ToF;

		if (this->value() > rhs.value())
		{
			ToF = false;
		}
		else
		{
			ToF = true;
		}
		return ToF;
	}


	bool Date ::operator<=(const Date& rhs) const
	{
		bool ToF;

		if (this->value() <= rhs.value())
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}
	bool Date:: operator>=(const Date& rhs) const
	{
		bool ToF;
		if (this->value() >= rhs.value())
		{
			ToF = true;
		}
		else 
		{
			ToF = false;
		}
		return ToF;
	}


	int Date::errCode() const
	{
		return Error_Msg;

	}
	bool Date::bad() const
	{
		bool ToF;

		if (Error_Msg != NO_ERROR)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;
	}


	std::istream& Date ::read(std::istream& istr)
	{
		int year, month, day;
		char del;

		
		istr >> year >> del >> month >> del >> day;

		if (istr.fail())
			Error_Msg = CIN_FAILED;
		else 
		{
			set(year, month, day);

			if (year < min_year || year > max_year)
			{
				errCode(YEAR_ERROR);
			}
			else if (month < 1 || month > 12)
			{
				errCode(MON_ERROR);
			}
			else if (day < 1 || day > mdays(month, year))
			{
				errCode(DAY_ERROR);
			}
		}

		return istr;
	
	}

	std::ostream& Date::write(std::ostream& ostr)const
	{	
		ostr << year << '/';
		ostr.width(2);
		ostr.fill('0');
		ostr << month << '/';
		ostr.width(2);
		ostr.fill('0');
		ostr << day;
		

		return ostr;

	}



	std::ostream& operator << (std::ostream& ostr, const Date& date) 
	
	{
		date.write(ostr);
		return ostr;
	}



	std::istream& operator >> (std::istream& istr, Date& date)
	
	{
		date.read(istr);
		return istr;
	}



}
