//Author:   Nick Seyler
//Date:     1/20/17
//File:     complex_test.cpp

#include "complex.h"
#include <cassert>
#include <iostream>
#include <cmath>

int main()
{
	complex c1(5, 7.1);
	assert(c1.get_real() == 5);
	assert(c1.get_imaginary() == 7.1);
	c1.display();

	complex c2(1, 2);
	complex c3(-3, 4);

	complex c4 = c2 + c3;
	assert(c4.get_real() == -2);
	assert(c4.get_imaginary() == 6);

	complex c5 = c2 - c3;
	assert(c5.get_real() == 4);
	assert(c5.get_imaginary() == -2);

	complex c6 = c2 * c3;
	assert(c6.get_real() == -11);
	assert(c6.get_imaginary() == -2);

	complex c7(3, 2);
	complex c8(4, -3);
	complex c9 = c7 / c8;
	assert(c9.get_real() == 6 / 25.0);
	assert(c9.get_imaginary() == 17 / 25.0);

	std::cout << "passed all tests" << std::endl;
	return 0;
}
