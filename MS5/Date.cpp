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

	Date::Date()
	{
		year = 0;
		month = 0;
		day = 0;
		pair = 0;
		Error_Msg = NO_ERROR;
	}

	Date::Date(int Y, int M, int D)
	{
		bool v_year = Y >= min_year && Y <= max_year;
		int MD = mdays(M, Y);
		bool v_month = MD != -1 && D <= MD;
		

		if (v_year && v_month)
		{
			year = Y;
			month = M;
			day = D;
			Error_Msg = NO_ERROR;
			pair = Y * 372 + M * 13 + D;

		}
		else
		{
			*this = Date();
			Error_Msg = NO_ERROR;
		}

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

		if (!(*this == rhs))
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
		if (this->year < rhs.year)
		{
			return true;
		}
		else if (this->year == rhs.year && this->month < rhs.month)
		{
			return true;
		}
		else if (this->year == rhs.year && this->month == rhs.month && this->day < rhs.day)
		{
			return true;
		}
		else
			return false;
	}

	bool Date ::operator > (const Date& rhs) const
	{
		

		if (!(*this < rhs))
		{
			return false;
		}
		else
		{
			return true;
		}
		
	}


	bool Date ::operator<=(const Date& rhs) const
	{
		bool ToF;

		if (*this < rhs || *this == rhs)
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
		if (*this > rhs || *this == rhs)
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


	std::istream& Date::read(std::istream& istr)
	{
		//int year, month, day;
		char del;

		errCode(NO_ERROR);
		istr >> year >> del >> month >> del >> day;

		if (istr.fail())
		{
			*this = Date();
			errCode(NO_ERROR);

		}

		if (year < min_year || year > max_year)
		{
			*this =Date();
			errCode(YEAR_ERROR);
		}
		else if (month < 1 || month > 12)
		{
			*this = Date();
			errCode(MON_ERROR);
		}
		else if (day < 1 || day > mdays(month, year))
		{
			*this = Date();
			errCode(DAY_ERROR);
		}

		istr.clear();
		return istr;

	}

	std::ostream& Date::write(std::ostream& ostr)const
	{
		ostr << year << '/';
		if (month < 10)
			ostr << 0;
		ostr << month << '/';
		if (day < 10)
			ostr << 0;
		ostr << day;


		return ostr;

	}



	std::ostream& operator << (std::ostream& ostr, const Date& date)

	{
		return date.write(ostr);
		
	}



	std::istream& operator >> (std::istream& istr, Date& date1)

	{
		return date1.read(istr);
		
	}



}
