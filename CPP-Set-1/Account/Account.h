//Author:   Nick Seyler
//Date:     1/29/17
//File:     account.h

#ifndef ACCOUNT_H
#define ACCOUNT_H

class account
{
public:
	account(double b = 0, double r = 0);
	//precondition: b >= 0, r >= 0
	//postcondition: An account with balance b and rate r is created

	double getBalance() const;
	//postcondition: The balance is returned

	double getRate() const;
	//postcondition: The rate is returned

	void changeBalance(double newBalance);
	//precondition: newBalance >= 0
	//postcondition: The balance is changed to newBalance

	void changeRate(double newRate);
	//precondition: newRate >= 0
	//postcondition: The rate is changed to newRate

	void deposit(double money = 0);
	//precondition: money > 0
	//postcondition: money is added to balance

	void withdraw(double money = 0);
	//precondition: money <= balance
	//postcondition: money is subtracted from balance

	void interest(double years);
	//precondition: years > 0
	//postcondition: Interest is added to balance with respect to year and rate

private:
	double balance;
	double rate;

};

#endif