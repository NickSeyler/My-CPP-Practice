//Author:   Nick Seyler
//Date:     3/9/17
//File:     deque_test.cpp

#include <cstdlib>
#include <cassert>
#include <iostream>
#include "deque.h"

int main()
{
	deque<int> dq;
	assert (dq.size() == 0);
	assert (dq.empty() == true);
	
	dq.push_front(2);
	dq.push_back(3);
	dq.push_front(1);
	dq.push_back(4);
	assert (dq.size() == 4);
	std::cout << dq << std::endl;
	std::cout << "The front is: " << dq.front() << std::endl;
	std::cout << "The back is: " << dq.back() << std::endl;
	std::cout << std::endl;
	
	dq.push_back(5);
	dq.push_back(6);
	dq.push_back(7);
	dq.push_back(8);
	dq.push_back(9);
	dq.push_back(10);
	assert (dq.full() == true);
	dq.pop_front();
	dq.pop_back();
	std::cout << dq << std::endl;
	std::cout << "The front is: " << dq.front() << std::endl;
	std::cout << "The back is: " << dq.back() << std::endl;
	std::cout << std::endl;
	
	deque<int> dq2;
	
	dq2.push_front(3);
	dq2.push_front(2);
	dq2.push_front(1);
	
	deque<int> dq3;
	dq3.push_back(1);
	dq3.push_back(2);
	dq3.push_back(3);
	assert (dq2 == dq3);
	std::cout << "all tests passed" << std::endl;
	
	
	
	
	return 0;
}