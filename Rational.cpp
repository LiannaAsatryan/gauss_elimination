#ifndef __RATIONAL_H_
#define __RATIONAL_H_

#include "Rational.h"

Rational::Rational(double a)
{
	int p = 1;
	while(a > (int)a) {
		a *= 10;
		p *= 10;
	}
	numerator = a;
	denominator = p;
	reduce();
}
  
Rational::Rational(std::string str)
{
	double a = std::stod(str);
	int p = 1;
	while(a > (int)a) {
		a *= 10;
		p *= 10;
	}
	numerator = a;
	denominator = p;
	reduce();
}

Rational::Rational()
{
        numerator = 0;
        denominator = 1;
}

Rational::Rational(int n, int d)
{
        numerator = d < 0 ? -n : n;
        denominator = d < 0 ? -d : d;
        reduce();
}

void Rational::reduce()
{
        int min = abs(numerator) > abs(denominator) ? abs(denominator) : abs(numerator);
        for (int i = 2; i <= min; i++)
        {
                if (numerator % i == 0 && denominator % i == 0)
                {
                        numerator /= i;
                        denominator /= i;
                }
        }
        if (denominator < 0) {
                numerator *= -1;
                denominator *= -1;
        }
}

Rational::~Rational() {};

Rational Rational::add(const Rational& a)
{
        Rational t;
        t.numerator = a.numerator * denominator + a.denominator * numerator;
        t.denominator = a.denominator * denominator;
        t.reduce();
        return t;
}

Rational Rational::multiply(const Rational& a)
{
        Rational t;
        t.numerator = numerator * a.numerator;
        t.denominator = denominator * a.denominator;
        t.reduce();
        return t;
}

Rational Rational::divide(int a)
{
        Rational t;
        t.numerator = numerator;
        t.denominator = denominator * a;
        t.reduce();
        return t;
}

Rational Rational::divide(const Rational& a)
{
        Rational t;
        t.numerator = numerator * a.denominator;
        t.denominator = denominator * a.numerator;
        t.reduce();
        return t;
}

Rational Rational::neg()
{
        Rational t;
        t.numerator = -numerator;
        t.denominator = denominator;
        return t;
}
void Rational::print()
{
        reduce();
        if (numerator == 0) {
                std::cout << '0';
        }
        else if (denominator == 1) {
                std::cout << numerator;
        }
        else {
                std::cout << numerator << '/' << denominator;
        }
}

void Rational::to_string(std::string &str)
{
	reduce();
        if (numerator == 0) {
                str = "0";
        }
        else if (denominator == 1) {
                str=std::to_string(numerator);
        }
        else {
                str = std::to_string(numerator) + '/' + std::to_string(denominator);
        }

}

int Rational::get_numerator()
{
        return numerator;
}

int Rational::get_denominator()
{
        return denominator;
}       
#endif
