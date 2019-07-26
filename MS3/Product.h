// Final Project Milestone 3
//
// Version 1.0
// -----------------------------------------------------------
// Name: Fabio Bernal     Date: 7 / 29 / 2018     Reason: cause i have too
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#ifndef  AMA_PRODUCT_H
#define AMA_PRODUCT_H
#include "ErrorState.h"


namespace AMA
{
	const int MAX_SKU = 7;
	const int MAX_UNIT = 10;
	const int MAX_PRODUCT_LENGTH = 75;
	const double MAX_TAX = 0.13;
	
	const int max_sku_length = MAX_SKU;
	const int max_name_length = MAX_PRODUCT_LENGTH;
	const int max_unit_length = MAX_UNIT;

	class Product
	{
	private:
		char type_of_product;
		char product_sku[max_sku_length +1];
		char product_unit[max_unit_length +1];
		char *product_memory;
		int current_product_quantity;
		int needed_product_quantity;
		double single_unit_before_tax;
		bool Tax;
		ErrorState error;

	protected:

		void name(const char* ); //done
		const char* name() const; //done
		const char* sku() const; //done
		const char* unit() const; //done
		bool taxed() const; //done
		double price() const;//done
		double cost() const; //done
		void message(const char*);
		bool isClear() const;

	public:
		
		Product(char type= 'N'); // done
		Product(const char* , const char*, const char*, int=0, bool =true, double =0.0, int =0);
		Product(const Product& temp);
		Product& operator = (const Product& temp);
		~Product();
		
		
		std::fstream& store(std::fstream& file, bool newLine = true) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		bool operator==(const char*) const;
		double total_cost() const;
		void quantity(int);
		bool isEmpty() const;
		int qtyNeeded() const;
		int quantity() const;
		bool operator>(const char*) const;
		bool operator>(const Product&) const;
		int operator+=(int);

	};

	// Helpfer Functions
	std::ostream& operator<<(std::ostream&, const Product&);
	std::istream& operator>>(std::istream&, Product&);
	double operator+=(double&, const Product&);



}


#endif 