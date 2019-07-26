// -----------------------------------------------------------
// Name  Fabio Bernal             Date    8/8/2018         
/////////////////////////////////////////////////////////////////


#include <iostream>
#include <iomanip>
#include "Perishable.h"


using namespace std;


namespace AMA
{

	Perishable::Perishable() : Product('P')
	{
		date = Date();

	}


	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{
		Product::store(file, false);
		file << ',' <<Date(date) << endl;
		return file;

	}

	std::fstream & Perishable::load(std::fstream & file)
	{
		Product::load(file);
		date.read(file);
		file.ignore();
		return file;

	}


	std::ostream&  Perishable :: write(std::ostream& os, bool linear) const
	{
		Product::write(os, linear);

		if (isClear() && !isEmpty())
		{
			if (linear)
			{
				date.write(os);
			}
			else
			{
				os << "\n Expiry date: ";
				date.write(os);
			}

		}
		return os;

	}



	std::istream & Perishable::read(std:: istream & is)
	{
		
		Product::read(is);

		if (error.isClear())
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			date.read(is);
		}

		if (date.errCode() == CIN_FAILED)
		{
		
			error.message("Invalid Date Entry");
		}

		else if (date.errCode() == YEAR_ERROR)
		{
			error.message("Invalid Year in Date Entry");
		}

		else if (date.errCode() == MON_ERROR)
		{
			error.message("Invalid Month in Date Entry");
		}

		else if (date.errCode() == DAY_ERROR)
		{
			error.message("Invalid Day in Date Entry");
		}
		else
		{
			error.clear();
		}
		if (date.bad())
		{
			is.setstate(std::ios::failbit);

		}

		return is;
	}

	const Date& Perishable::expiry() const
	{
		return date;
	}

}