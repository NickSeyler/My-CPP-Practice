//Author:   Nick Seyler
//Date:     1/29/17
//File:     account.cpp

#include "Account.h"
#include <cassert>

account::account(double b, double r)
{
	assert(b >= 0 && r >= 0);
	balance = b;
	rate = r;
}

double account::getBalance() const
{
	return balance;
}

double account::getRate() const
{
	return rate;
}

void account::changeBalance(double newBalance)
{
	assert(newBalance >= 0);
	balance = newBalance;
}

void account::changeRate(double newRate)
{
	assert(newRate >= 0);
	rate = newRate;
}

void account::deposit(double money)
{
	assert(money > 0);
	balance += money;
}

void account::withdraw(double money)
{
	assert(money <= balance);
	balance -= money;
}

void account::interest(double years)
{
	assert(years > 0);
	balance = balance * (1 + rate * years);
}
