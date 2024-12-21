// Fraction.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>

using namespace std;

class Fraction
{
public:
	Fraction()
	{
		_numerator = 1;
		_denominator = 1;
	}
	Fraction(int numerator, int denominator = 1)
	{
		_numerator = numerator;

		if (denominator == 0)
		{
			_denominator = 1;
			cout << "Denominator in cannot be 0, by default it was replaced to 1." << endl;
		}
		else 
			_denominator = denominator;
		
	}

	void setNumerator(int numerator)
	{
		_numerator = numerator;
	}

	int getNumerator()
	{
		return _numerator;
	}

	void setDenominator(int denominator)
	{
		_denominator = denominator;
	}

	int getDenominator()
	{
		return _denominator;
	}

	double toDouble()
	{
		return (double) _numerator / _denominator;
	}

	void equalTo(Fraction fraction) {
		_numerator = fraction._numerator;
		_denominator = fraction._denominator;
		fatorize();
	}

	void fatorize()
	{
		int counter = 2;
		while (counter < 10)
		{
			if (_numerator % counter == 0 && _denominator % counter == 0)
			{
				_numerator /= counter;
				_denominator /= counter;
				counter = 2;
			}
			else
			{
				counter++;
			}
		}
	}

	//Add one fraction to another
	void add(Fraction fraction) {
		_numerator = (_numerator * fraction._denominator) +
			(fraction._numerator * _denominator);
		_denominator = _denominator * fraction._denominator;
		fatorize();
	}

	//Return the sum of two fractions
	static Fraction sum(Fraction fraction1,Fraction fraction2) {
		int n = (fraction1._numerator * fraction2._denominator) +
			(fraction2._numerator * fraction1._denominator);
		int d = fraction1._denominator * fraction2._denominator;

		Fraction f(1, 1);
		f.setNumerator(n);
		f.setDenominator(d);

		f.fatorize();

		return f;
	}

	//Add one fraction into another
	void subtract(Fraction fraction) {
		_numerator = (_numerator * fraction._denominator) -
			(fraction._numerator * _denominator);
		_denominator = _denominator * fraction._denominator;
		fatorize();
	}

	//Return the subtraction of two fractions
	static Fraction subtract(Fraction fraction1, Fraction fraction2) {
		int n = (fraction1._numerator * fraction2._denominator) -
			(fraction2._numerator * fraction1._denominator);
		int d = fraction1._denominator * fraction2._denominator;

		Fraction f(1, 1);
		f.setNumerator(n);
		f.setDenominator(d);

		f.fatorize();

		return f;
	}

	//Add one fraction with another
	void multiply(Fraction fraction) {
		_numerator = (_numerator * fraction._numerator);
		_denominator = _denominator * fraction._denominator;
		fatorize();
	}

	//Return the multiplication of two fractions
	static Fraction multiply(Fraction fraction1, Fraction fraction2) {
		int n = (fraction1._numerator * fraction2._numerator);
		int d = fraction1._denominator * fraction2._denominator;

		Fraction f(1, 1);
		f.setNumerator(n);
		f.setDenominator(d);

		f.fatorize();

		return f;
	}

	//Add one fraction by another
	void divide(Fraction fraction) {
		_numerator = (_numerator * fraction._denominator);
		_denominator = _denominator * fraction._numerator;
		fatorize();
	}

	//Return the division of two fractions
	static Fraction divide(Fraction fraction1, Fraction fraction2) {
		int n = (fraction1._numerator * fraction2._denominator);
		int d = fraction1._denominator * fraction2._numerator;

		Fraction f(1, 1);
		f.setNumerator(n);
		f.setDenominator(d);

		f.fatorize();

		return f;
	}

	//Show the fraction structure
	void displayFraction()
	{
		cout << _numerator << "/" << _denominator << endl;
	}

private:
	int _numerator;
	int _denominator;
};

int main()
{
	Fraction p(1, 3); //Fraction p
	Fraction q(2, 4); //Fraction q
	Fraction s; //Object with default constructor numerator = 1 and denominator = 1

	cout << "Fraction 1: ";
	p.displayFraction();

	cout << "Fraction 2: ";
	q.displayFraction();

	cout << "-------------------" << endl;

	s = Fraction::sum(p, q);
	cout << "SUM = ";
	s.displayFraction();

	s = Fraction::subtract(p, q);
	cout << "SUBTRACTION = ";
	s.displayFraction();

	s = Fraction::multiply(p, q);
	cout << "MULTIPLICATION = ";
	s.displayFraction();

	s = Fraction::divide(p, q);
	cout << "DIVISION = ";
	s.displayFraction();

	cout << endl;

	//Assignment
	cout << "p = s" << "\n"; //Show the operation structure

	p.equalTo(s); // p = q
	
	cout << "p = " << p.getNumerator() << "/" << p.getDenominator() <<
		" = " << p.toDouble() << endl;
	
}