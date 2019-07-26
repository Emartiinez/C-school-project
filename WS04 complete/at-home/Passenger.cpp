// TODO: add file header comments here
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;


// TODO: add your headers here

namespace sict
{



	void Passenger::set()
	{
		Passenger_Name[0] = '\0';
		Destination[0] = '\0';
		year = 0;
		month = 0;
		day = 0;

	}

	Passenger::Passenger()
	{
		set();
	}
	

	Passenger::Passenger(const char* passengerName, const char* p_Destination)
	{
		if (passengerName != '\0' && p_Destination != '\0')
		{
			strcpy(Passenger_Name, passengerName);
			strcpy(Destination, p_Destination);
		}

		else
		{
			set();
		}
	}

	Passenger::Passenger(const char* name, const char* Pdestination, int Pyear, int Pmonth, int Pday)
	{
		if (name != '\0' && Pdestination != '\0')
		{
			if (Pyear >= MIN_YEAR && Pyear <= MAX_YEAR && Pmonth >= MIN_MONTH && Pmonth <= MAX_MONTH && Pday >= MIN_DAY && Pday <= MAX_DAY)
			{
				strncpy(Passenger_Name, name, MAX_NAME);
				strncpy(Destination, Pdestination, MAX_NAME);
				year = Pyear;
				month = Pmonth;
				day = Pday;
			}
		}
		else
		{
			set();

		}

	}

	//END of CONSTRUCTORS



	bool Passenger::isEmpty() const
	{
		bool ToF;

		if (Passenger_Name[0] != '\0' && Destination[0] != '\0')
		{
			ToF = false;
		}
		else
		{
			ToF = true;
		}
		return ToF;
	}

	void Passenger::display()const

	{
		if (!isEmpty())
		{
			cout << Passenger_Name << " - " << Destination << " on " << year << "/";
			cout.width(2);
			cout.fill('0');
			cout << month << "/";
			cout.width(2);
			cout.fill('0');
			cout<< day << endl;

		}
		else
		{
			cout << "No Passenger!" << endl;

		}
	}

	const char* Passenger::name()const
	{
		//return (!isEmpty() ? Passenger_Name : nullptr);

		if (!isEmpty())
		{
			return Passenger_Name;
		}
		else
		{
			return nullptr;
		}

	}

	bool Passenger::canTravelWith(const Passenger& passenger) const
	{
		bool ToF;

		if (!strcmp(passenger.Destination,Destination) && passenger.year == year && passenger.month == month && passenger.day == day)
		{
			ToF = true;
		}
		else
		{
			ToF = false;
		}
		return ToF;

	}












}




