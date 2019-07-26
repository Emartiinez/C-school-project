/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 2.0
// Date 2018 / 05 /24
// Author Fabio Bernal
// Description
// Workshop lab 2
// oop 244 scc
***********************************************************/
#include <iostream>
#include "Kingdom.h"
using namespace std;



// TODO: the sict namespace
namespace sict
{

	void display(const Kingdom& kingdom)
	{

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}
	void display(const Kingdom* pKingdom, int size)
	{
		int sum=0;

		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". ";
			display(pKingdom[i]);
			sum += pKingdom[i].m_population;

		}
		cout << "------------------------------" << endl;
		cout << "Total population of SICT: " << sum << endl;
		cout << "------------------------------" << endl;
	}

}



    