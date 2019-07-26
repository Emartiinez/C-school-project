#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
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


		if (product_memory != nullptr)
		{
			return product_memory;
		}
		else
		{
			return nullptr;
		}
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

		strncpy(product_sku, sku, max_sku_length +1);
		product_sku[strlen(sku)] = '\0';

		strncpy(product_unit, unit, max_unit_length +1);
		product_unit[strlen(unit)] = '\0';


		current_product_quantity = quantity;
		single_unit_before_tax = beforeTax;
		Tax = taxable;
		needed_product_quantity = qntyNeeded;
		name(address);
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

		delete[] product_memory;

		error.clear();
	}


	Product& Product ::operator = (const Product& temp)
	{

		if (this != &temp)
		{
			strncpy(product_sku, temp.product_sku, max_sku_length + 1);
			product_sku[strlen(temp.product_sku)] = '\0';


			strncpy(product_unit, temp.product_unit, max_unit_length + 1);
			product_unit[strlen(temp.product_unit)] = '\0';

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
		file << type_of_product << ',' << product_sku << ',' << product_memory << ',' << product_unit << ',' << Tax << ',' << single_unit_before_tax << ',' << current_product_quantity << ',' << needed_product_quantity;

		if (newLine)
		{
			file << endl;
		}

		return file;
	}



	std::fstream& Product::load(std::fstream& file)
	{

		char sku[max_sku_length +1];
		char name[max_name_length +1];
		char unit[max_unit_length +1];
		double price;
		int quantity, need;
		char taxed;
		bool TOF;



		if (file.is_open())
		{
			file.getline(sku, max_sku_length, ',');
			sku[strlen(sku)] = '\0';

			file.getline(name, max_name_length, ',');
			name[strlen(name)] = '\0';

			file.getline(unit, max_unit_length, ',');
			unit[strlen(unit)] = '\0';

			file >> taxed;

			if (taxed == '1')
			{
				TOF = true;
			}
			else if (taxed == '0')
			{
				TOF = false;
			}

			file.ignore();
			file >> price;
			file.ignore();
			file >> quantity;
			file.ignore();
			file >> need;
			file.ignore();

			*this = Product(sku, name, unit, quantity, TOF, price, need);

		}
		return file;
	}




	//changed
	std::ostream& Product::write(std::ostream& os, bool linear) const
	{

		if (error.isClear())
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
				os << " Sku: " << sku() << endl
					<< " Name (no spaces): " << name() << endl
					<< " Price: " << price() << endl
					<< " Price after tax: ";

				if (taxed())
				{
					os << cost() << endl;
				}

				else
				{
					os << "N/A" << endl;
				}
					os << " Quantity on Hand: " << quantity() << " " << unit() << endl
						<< " Quantity needed: " << qtyNeeded();
				
			}
		}

		else
		{
			os << error.message();
		}

		return os;
	}






	std::istream& Product::read(std::istream& is)
	{

		char *p_name = new char[max_name_length + 1];
		char tax;

		is.clear();

		cout << " Sku: ";
		is >> product_sku;


		cout << " Name (no spaces): ";
		is >> p_name;
		name(p_name);

		cout << " Unit: ";
		is >> product_unit;

		cout << " Taxed? (y/n): ";
		is >> tax;

		if (tax == 'y' || tax == 'Y')
		{
			Tax = true;
		}
		else if (tax == 'n' || tax == 'N')
		{
			Tax = false;
		}
		else
		{
			error.message("Only (Y)es or (N)o are acceptable");
			is.setstate(ios::failbit);
			return is;
		}


		if (!is.fail())
		{

			cout << " Price: ";
			is >> single_unit_before_tax;

			if (is.fail())
			{
				error.message("Invalid Price Entry");
				is.setstate(ios::failbit);
				return is;
			}
		}


		if (!is.fail())
		{
			cout << " Quantity on hand: ";
			is >> current_product_quantity;
		
			if (is.fail())
			{
				error.message("Invalid Quantity Entry");
				is.setstate(ios::failbit);
				return is;
			}

		}


		if (!is.fail())
		{
			cout << " Quantity needed: ";
			is >> needed_product_quantity;
			cin.ignore();
			if (is.fail())
			{
				error.message("Invalid Quantity Needed Entry");
				is.setstate(ios::failbit);
				return is;
			}
		}


		error.clear();
		return is;
	}






	bool Product ::operator== (const char* name) const
	{
		bool TOF;

		if (strcmp(name, product_sku) == 0)

		{
			TOF = true;
		}
		else
		{
			TOF = false;
		}
		return TOF;
	}



	double Product::total_cost() const
	{
		return current_product_quantity * cost();
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



	int Product::quantity() const
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

	bool Product :: operator>(const iProduct& temp) const
	{
		bool TOF;

		if (strcmp(product_memory, temp.name()) > 0)
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

	std::ostream& operator<<(std::ostream& os, const iProduct& temp)

	{
		return temp.write(os, true);

	}

	std::istream& operator>>(std::istream& is, iProduct& temp)
	{
		temp.read(is);
		return is;
	}

	double operator+=(double& A, const iProduct& temp)
	{
		return A + temp.total_cost();
	}






}