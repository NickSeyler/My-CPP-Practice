//Author:   Nick Seyler
//Date:     1/29/17
//File:     date.h

#ifndef DATE_H
#define DATE_H

class date
{
public:
	date(int m = 1, int d = 1, int y = 1970);
	//precondition: Year >=1, the date must be valid
	//postcondition: A date has been created

	int getMonth() const;
	//postcondition: The month is returned

	int getDay() const;
	//postcondition: The day is returned

	int getYear() const;
	//postcondition: The year is returned

	void next();
	//postcondition: The date is changed to the next day

	void displayNum();
	//postcondition: The date is displayed in number format

	void displayWord();
	//postcodition: The date is displayed in word format

private:
	int month;
	int day;
	int year;
};

#endif
