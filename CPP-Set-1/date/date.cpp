//Author:   Nick Seyler
//Date:     1/29/17
//File:     date.cpp

#include "date.h"
#include <cassert>
#include <iostream>
#include <string>

bool isThirtyMonth(int m)
{
    if (m == 4 || m == 6 || m == 9 || m == 1)
        return true;
    else
        return false;
}

bool isThirtyOneMonth(int m)
{
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return true;
    else
        return false;
}

bool isLeapYear(int y)
{
    if (y % 400 == 0)
        return true;
    else if (y % 4 == 0 && y % 100 != 0)
        return true;
    else
        return false;
}

std::string checkMonth(int m)
{
    if (m == 1)
        return "January";
    else if (m == 2)
        return "February";
    else if (m == 3)
        return "March";
    else if (m == 4)
        return "April";
    else if (m == 5)
        return "May";
    else if (m == 6)
        return "June";
    else if (m == 7)
        return "July";
    else if (m == 8)
        return "August";
    else if (m == 9)
        return "September";
    else if (m == 10)
        return "October";
    else if (m == 11)
        return "November";
    else
        return "December";
}

std::string checkDay(int d)
{
    if (d == 1)
        return "st";
    else if (d == 2)
        return "nd";
    else if (d == 3)
        return "rd";
    else
        return "th";
}


date::date(int m, int d, int y)
{
    assert(m >= 1 && m <= 12);
    assert(y >= 1);
    assert(d >= 1);
    if (isThirtyOneMonth(m))
        assert(d <= 31);
    else if (m == 2)//february
        if (isLeapYear(y))
            assert(d <= 29);
        else
            assert(d <= 28);
    else //months with 30 days
        assert(d <= 30);

    month = m;
    day = d;
    year = y;
}

int date::getMonth() const
{
    return month;
}

int date::getDay() const
{
    return day;
}

int date::getYear() const
{
    return year;
}

void date::next()
{
    if (day == 31)
    {
        day = 1;
        if (month == 12)
        {
            month = 1;
            year++;
        }
        else
            month++;

    }
    else if (day == 30)
    {
        if (isThirtyMonth(month))
        {
            day = 1;
            month++;
        }
        else
            day++;
    }
    else if (day == 29 && month == 2)
    {
        day = 1;
        month++;
    }

    else if (day == 28 && month == 2)
    {
        if (isLeapYear(year))
            day++;
        else
        {
            day = 1;
            month++;
        }
    }
    else
        day++;
}

void date::displayNum()
{
    std::cout << "The date is " << month << "/" << day << "/" << year << std::endl;
}

void date::displayWord()
{
    std::cout << "The date is " << checkMonth(month) << " " << day <<
        checkDay(day) << ", " << year << std::endl;
}