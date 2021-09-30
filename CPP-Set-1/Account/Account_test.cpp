//Author:   Nick Seyler
//Date:     1/29/17
//File:     account_test.cpp

#include "Account.h"
#include <cassert>
#include <iostream>

int main()
{
   account a1(5000, .14);
   assert (a1.getBalance() == 5000);
   assert (a1.getRate() == .14);
   
   a1.deposit(200);
   assert (a1.getBalance() == 5200);
   
   a1.withdraw(1200);
   assert (a1.getBalance() == 4000);
   
   a1.changeBalance(333);
   assert (a1.getBalance() == 333);
   
   a1.changeRate(.16);
   assert(a1.getRate() == .16);
   
   
   account a2(1000, .01);
   a2.interest(2);
   assert(a2.getBalance() == 1020);
   
   std::cout << "passed all tests" << std::endl;
   return 0;
}
