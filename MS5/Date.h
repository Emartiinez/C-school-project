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
// Name: Fabio Bernal     Date: 7 / 11 / 2018     Reason: cause i have too
/////////////////////////////////////////////////////////////////

#ifndef AMA_DATE_H
#define AMA_DATE_H

namespace AMA {


#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

	
	
	const int min_year = 2000;
	const int max_year = 2030;
	const int MIN_MON = 1;
	const int MAX_MON = 12;

	const double TAX = 0.13;

  class Date {
	  int year;
	  int month;
	  int day;
	  int pair;
	  int Error_Msg;

	  int value() const; //DONE 
	  void errCode(int errorCode);  //DONE 

	 
 
  public:
	
	  Date();  //DONE 
	  Date(int year , int month , int day);  //DONE  

	  bool operator==(const Date& rhs) const; 
	  bool operator!=(const Date& rhs) const;
	  bool operator<(const Date& rhs) const;
	  bool operator>(const Date& rhs) const;
	  bool operator<=(const Date& rhs) const;
	  bool operator>=(const Date& rhs) const;

	  int mdays(int, int)const;  //DONE 

	  int errCode() const;
	  bool bad() const;

	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;

	
  };
  std::ostream& operator << (std::ostream& ostr, const Date& date);
  std::istream& operator >> (std::istream& istr, Date& date);
}
#endif