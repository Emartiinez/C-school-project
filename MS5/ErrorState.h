// Final Project Milestone 2
//
// Version 1.0
// -----------------------------------------------------------
// Name: Fabio Bernal     Date: 7 / 17 / 2018     Reason: cause i have too
/////////////////////////////////////////////////////////////////

#ifndef AMA_ERRORSTATE_H
#define AMA_ERRORSTATE_H
#include <ostream>
#include <iostream>
#include <cstring>

namespace AMA
{

	class ErrorState
	{
		char *Error_message;

		
		void set(const char* errorMessage);

	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;

		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message()const;
	};

	std::ostream& operator << (std::ostream& ostr, const ErrorState& error_state);

}



#endif