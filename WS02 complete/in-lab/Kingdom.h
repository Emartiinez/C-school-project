/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.h
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name  Fabio Bernal    Date 2018/05/24    Reason workshop 2 Lab SCC
// 
///////////////////////////////////////////////////////////
***********************************************************/

// TODO: header safeguards

#ifndef NAMESPACE_SICT_KINGDOM_H
#define NAMESPACE_SICT_KINGDOM_H


namespace sict {

	struct Kingdom
	{
		char m_name[32];
		int m_population;
	};

	void display(const Kingdom&);
	void display(const Kingdom*, int);
}
#endif