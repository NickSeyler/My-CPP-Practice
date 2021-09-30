//Author:   Nick Seyler
//Date:     1/29/17
//File:     date_test.cpp

#include "date.h"
#include <cassert>
#include <iostream>

int main()
{
	date d1(2, 28, 2016);

	assert(d1.getMonth() == 2);
	assert(d1.getDay() == 28);
	assert(d1.getYear() == 2016);

	d1.next();
	assert(d1.getDay() == 29);

	d1.next();
	assert(d1.getDay() == 1);
	assert(d1.getMonth() == 3);

	date d2(12, 31, 2016);
	d2.next();
	assert(d2.getDay() == 1);
	assert(d2.getMonth() == 1);
	assert(d2.getYear() == 2017);

	date d3(4, 3, 1999);
	d3.displayNum();
	d3.displayWord();

	std::cout << "passed all tests" << std::endl;
	return 0;
}