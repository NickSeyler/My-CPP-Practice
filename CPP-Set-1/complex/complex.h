//Author:   Nick Seyler
//Date:     1/20/17
//File:     complex.h

#ifndef COMPLEX_H
#define COMPLEX_H

class complex
{
public:
	complex(double a = 0.0, double b = 0.0);
	// postconditions: complex number is created

	double get_real() const;
	// postconditions: the real number has been returned
	double get_imaginary() const;
	// postconditions: the real part of the imaginary number has been returned
	void display();
	// postconditions: the entire complex number will be displayed


private:
	double real;
	double imaginary;
};

complex operator + (const complex& c1, const complex& c2);
// postcondition: sum of c1 & c2 has been returned

complex operator - (const complex& c1, const complex& c2);
// postcondition: difference of c1 & c2 has been returned

complex operator * (const complex& c1, const complex& c2);
// postcondition: product of c1 & c2 has been returned

complex operator / (const complex& c1, const complex& c2);
// precondition: c2 is not 0
// postcondition: quotient of c1 & c2 has been returned

#endif