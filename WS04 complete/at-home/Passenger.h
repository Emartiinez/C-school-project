// TODO: add file header comments here

#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: add header file guard here
namespace sict
{

	const int MAX_NAME = 32;

	const int MAX_YEAR = 2020;
	const int MIN_YEAR = 2017;
	
	const int MAX_MONTH = 12;
	const int MIN_MONTH = 1;
	
	const int MAX_DAY = 31;
	const int MIN_DAY = 1;


	class Passenger
	{
		char Passenger_Name[MAX_NAME];
		char Destination[MAX_NAME];
		int year;
		int month;
		int day;

		
	public:
		
		Passenger();
		Passenger(const char* ,const char* );
		Passenger(const char*, const char*, int ,int ,int);

		bool isEmpty() const;
		void display() const;
		const char* name()const;
		bool canTravelWith(const Passenger&) const;
	
		void set();

	};


}


#endif 