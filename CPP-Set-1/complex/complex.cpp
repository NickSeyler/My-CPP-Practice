//Author:   Nick Seyler
//Date:     1/20/17
//File:     complex.cpp
//Description: Add real and imaginary numbers to get a complex number.

#include "complex.h"
#include <cassert>
#include <iostream>
#include <cmath>

complex::complex(double a, double b)
{
	real = a;
	imaginary = b;
}

double complex::get_real() const
{
	return real;
}

double complex::get_imaginary() const
{
	return imaginary;
}

void complex::display()
{
	std::cout << "The complex number is " << get_real() << " + " << get_imaginary() << "i" << std::endl;
}

complex operator + (const complex& c1, const complex& c2)
{
	double a = c1.get_real() + c2.get_real();
	double b = c1.get_imaginary() + c2.get_imaginary();
	return complex(a, b);
}

complex operator - (const complex& c1, const complex& c2)
{
	double a = c1.get_real() - c2.get_real();
	double b = c1.get_imaginary() - c2.get_imaginary();
	return complex(a, b);
}

complex operator * (const complex& c1, const complex& c2)
{
	double a = c1.get_real() * c2.get_real() + c1.get_imaginary() * c2.get_imaginary() * -1;
	double b = c1.get_real() * c2.get_imaginary() + c2.get_real() * c1.get_imaginary();
	return complex(a, b);
}

complex operator / (const complex& c1, const complex& c2)
{
	assert(c2.get_real() != 0 && c2.get_imaginary() != 0);

	double a = c1.get_real() * c2.get_real() + c1.get_imaginary() * c2.get_imaginary();
	double b = c2.get_real() * c1.get_imaginary() - c1.get_real() * c2.get_imaginary();
	double denominator = c2.get_real() * c2.get_real() + c2.get_imaginary() * c2.get_imaginary();
	return complex(a / denominator, b / denominator);
}
