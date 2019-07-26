#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <memory>
#include "Product.h"
#include "ErrorState.h"


using namespace std;

namespace AMA
{
	void Product::name(const char* address)
	{
		if (address != nullptr)
		{
			
			product_memory = new char[strlen(address) + 1];
			strncpy(product_memory, address, strlen(address));
			product_memory[strlen(address)] = '\0';
		}

	}


	const char * Product::name() const
	{
		return product_memory;
		
	}


	const char * Product::sku() const
	{
		return product_sku;

	}

	const char * Product::unit() const
	{

		return product_unit;

	}

	bool Product::taxed() const
	{
		return Tax;
	}

	double Product::price() const
	{
		return single_unit_before_tax;
	}

	double Product::cost() const
	{
		if (taxed())
		{
			return (price() *(MAX_TAX + 1));
		}
		else
		{
			return price();
		}
	}
	
	void Product::message(const char* Error_Msg)
	{
		error.message(Error_Msg);
	}

	bool Product::isClear() const
	{
		return error.isClear();

	}










	// Constructor and Destructor
	Product::Product(char productType)
	{
		type_of_product = productType;
		product_sku[0] = '\0';
		product_unit[0] = '\0';
		product_memory = nullptr;
		current_product_quantity = 0;
		needed_product_quantity = 0;
		single_unit_before_tax = 0.0;
		Tax = false;
		

	}
	Product::Product(const char* sku, const char*address, const char*unit, int quantity, bool taxable, double beforeTax, int qntyNeeded)
	{

		strncpy(product_sku, sku , max_sku_length+1);
		product_sku[strlen(sku) + 1] = '\0';

		strncpy(product_unit, unit, max_unit_length+1);
		product_unit[strlen(unit)+1] = '\0';

		name(address);

		current_product_quantity = quantity;
		single_unit_before_tax = beforeTax;
		Tax = taxable;
		needed_product_quantity = qntyNeeded;
	}

	Product::Product(const Product& temp)
	{
		if (temp.product_memory != nullptr)
		{
			product_memory = nullptr;
			*this = temp;
		}

	}

	Product ::~Product()
	{
		//
		delete[] product_memory;
		product_memory = nullptr;
		error.clear();
	}


	Product& Product ::operator = (const Product& temp)
	{

		if (this != &temp)
		{
			
			
			strncpy(product_sku, temp.product_sku, max_sku_length +1);
			product_sku[strlen(temp.product_sku )+1] = '\0';
			
			strncpy(product_unit, temp.product_unit, max_unit_length+1);
			product_unit[strlen(temp.product_sku) + 1] = '\0';
			
			type_of_product = temp.type_of_product;
			current_product_quantity = temp.current_product_quantity;
			needed_product_quantity = temp.needed_product_quantity;
			single_unit_before_tax = temp.single_unit_before_tax;
			Tax = temp.Tax;

			delete[]  product_memory;
			name(temp.product_memory);
		}

		return *this;

	}



	std::fstream& Product::store(std::fstream& file, bool newLine) const
	{
		file << type_of_product << ',' << product_sku << ',' << product_unit << ',' << product_memory << ',' << current_product_quantity << ',' << Tax << ',' << single_unit_before_tax << ',' << needed_product_quantity;

		if (newLine)
		{
			file << endl;
		}
		file.clear();
		file.close();
		return file;
	}



	std::fstream& Product::load(std::fstream& file)
	{
		Product P_temp;
		
		P_temp.product_memory = new char[MAX_PRODUCT_LENGTH + 1];

		if (file.is_open())
		{
			file >> P_temp.type_of_product >> P_temp.product_sku >> P_temp.product_unit >> P_temp.product_memory >> P_temp.current_product_quantity >> P_temp.Tax >> P_temp.single_unit_before_tax >> P_temp.needed_product_quantity;
			*this = P_temp;
		}
		delete[] P_temp.product_memory;
		P_temp.product_memory = nullptr;
		//

		return file;

	}

	



	std::ostream& Product::write(std::ostream& os, bool linear) const
	{
		if (linear)
		{
			os << setw(max_sku_length) << left << sku() << "|"
				<< setw(20) << left << name() << "|"
				<< setw(7) << fixed << setprecision(2) << right << cost() << "|"
				<< setw(4) << right << quantity() << "|"
				<< setw(10) << left << unit() << "|"
				<< setw(4) << right << qtyNeeded() << "|";

		}
		else
		{
			os << "SKU: " << sku() << "|" << endl
				<< "Name: " << name() << "|" << endl
				<< "Price: " << price() << "|" << endl;


			if (taxed())
			{
				os << "Price after tax: " << cost() << endl;
			}
			else
			{
				os << "N/A" << endl;
				os << "Quantity on hand: " << quantity() << endl
					<< "Quantity Needed: " << qtyNeeded() << endl;
			}

			
		}
		return os;

	}


	std::istream& Product::read(std::istream& is)
	{
		
		char p_sku[max_sku_length + 1];
		char p_unit[max_name_length + 1];
		char *p_name = new char[max_unit_length + 1];
		
		int p_current;
		int p_needed;
		
		double single_Unit;
		char tax;
		bool TOF;
		


		cout << " Sku: ";
		is >> p_sku;
		
		cout << " Name (no spaces): ";
		is >> p_name;
		
		cout << " Unit: ";
		is >> p_unit;
		
		cout << " Taxed? (y/n): ";
		is >> tax;
		
		if (tax == 'y' || tax == 'Y')
		{
			TOF = true;
		}
		else if (tax == 'n' || tax == 'N')
		{
			TOF = false;
		}
			
		else
		{
			is.setstate(ios::failbit);
			error.message("Only (Y)es or (N)o are acceptable");
		}

		if (!is.fail())
		{
			cout << " Price: ";
			is >> single_Unit;
			if (is.fail())
			{
				error.message("Invalid Price Entry");
			}
		}
		if (!is.fail())

		{
			cout << " Quantity on hand: ";
			is >> p_current;

			if (is.fail())
			{
				error.message("Invalid Quantity Entry");
			}
		}


		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> p_needed;

			if (is.fail())
			{
				error.message("Invalid Quantity Needed Entry");
			}

		}


		if (!is.fail())
		{
			
			*this= Product(p_sku, p_name, p_unit, p_current, TOF, single_Unit, p_needed);
			
		}//

		delete[] p_name;
		p_name = nullptr;
		return is;

	}

	bool Product ::operator== (const char* name) const
	{
		bool TOF;

		if (strcmp(name,product_sku)==0)

		{
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}


	// might change
	double Product:: total_cost() const
	{
		double total = quantity() * cost();
		return total;
	}


	void Product::quantity(int num_Units)
	{
		current_product_quantity = num_Units;
	}

	bool Product::isEmpty() const
	{
		bool TOF; 
		
		if (product_memory == nullptr)
		{
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}


	int Product::qtyNeeded() const
	{
		return needed_product_quantity;
	}

	int Product :: quantity() const
	{
		return current_product_quantity;
	}


	bool Product :: operator> (const char* sku) const
	{
		bool TOF;

		if (strcmp(product_sku, sku) > 0)
		{
			TOF = true;
		}

		else
		{
			TOF = false;
		}

		return TOF;
	}

	bool Product :: operator>(const Product& temp) const
	{
		bool TOF;

		if (strcmp(product_memory, temp.product_memory) >0)
		{
			TOF = true;
		}
		else
		{
			TOF = false;
		}

		return TOF;
	}

	int Product ::operator+=(int added)
	{
		if (added > 0)
		{
			current_product_quantity += added;
			return current_product_quantity;
		}
		else
		{
			return current_product_quantity;
		}

		
	}

	// Helper Functions

	std::ostream& operator<<(std::ostream& os, const Product& temp)

	{
		return temp.write(os, true);

	}

	std::istream& operator>>(std::istream& is , Product& temp)
	{
		temp.read(is);
		return is;
	}

	double operator+=(double& A, const Product& temp)
	{
		return A + temp.total_cost();
	}

}