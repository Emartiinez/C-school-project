// Final Project Milestone 2
//
// Version 1.0
// Date
// Author
// Description
// Revision History
// -----------------------------------------------------------
// Name: Fabio Bernal     Date: 7 / 17 / 2018    
/////////////////////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include "ErrorState.h"
#include <cstring>	

namespace AMA
{
	void ErrorState::set(const char* Error_msg)
	{
		Error_message = nullptr;
		if (Error_msg != nullptr)
		{
			message(Error_msg);
		}
		
		

	}
	ErrorState ::ErrorState(const char* errorMessage )
	{
		 
		set(errorMessage);

	}

	ErrorState:: ~ErrorState()
	{
		delete[]Error_message;
	}

	void ErrorState::clear()
	{
		delete[] Error_message;
		Error_message = nullptr;
	}

	bool ErrorState::isClear() const
	{
		bool TOF;

		if (Error_message == nullptr)
		{
			TOF = true;
		}
		else
		{
			TOF = false;
		}

		return TOF;
	}

	void ErrorState::message(const char* str)
	{
		clear();
		Error_message = new char[strlen(str) + 1];
		strncpy(Error_message, str, strlen(str) + 1);

	}
	const char* ErrorState:: message()const
	{
		return Error_message;
	}

	std::ostream& operator << (std::ostream& ostr, const ErrorState& error_state)
	{
		if(!error_state.isClear())
		{
			ostr << error_state.message();
		}
		return ostr;
	}


}
