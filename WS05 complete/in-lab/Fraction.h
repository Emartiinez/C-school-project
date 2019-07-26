// TODO: header file guard
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
// TODO: create namespace
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		int fraction_numerator;
		int fraction_denominator;
		bool valid;

		int max() const;
		int min() const;;
		int gcd() const;
		void reduce();
				// TODO: declare instance variables 

		// TODO: declare private member functions
		 
	public:
		// TODO: declare public member functions
		Fraction();
		Fraction(int numerator, int denominator);
		void display()const;
		bool isEmpty() const;
		Fraction operator + (const Fraction& rhs) const;
		Fraction operator * (const Fraction& rhs);
		bool operator == (const Fraction& rhs) const;
		bool operator != (const Fraction& rhs) const; 
		Fraction& operator += (const Fraction& rhs);
		

		// TODO: declare the + operator overload

	};

}

#endif 