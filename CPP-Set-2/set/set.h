//Author:   Nick Seyler
//Date:     2/7/17
//File:     set_test.h

#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>

class set
{
public:
	typedef int value_type;
	typedef std::size_t size_type;
	static const size_type CAPACITY = 30;

	set();
	// postcondition: empty set has been created

	void insert(const value_type& entry);
	// precondition: if entry is not in the set, set is not full
	// postcondition: entry is in the set

	void remove(const value_type& entry);
	// postcondition: entry is not in the set

	size_type size() const;
	// postcondition: number of elements in the set has been returned

	bool contains(const value_type& entry) const;
	// postcondition: whether entry is in the set has been returned

	friend set set_union(const set& s1, const set& s2);
	// postcondition: union of s1 & s2 has been returned

	friend set set_intersection(const set& s1, const set& s2);
	// postcondition: intersection of s1 & s2 has been returned

	friend set set_difference(const set& s1, const set& s2);
	// postcondition: difference of s1 - s2 has been returned

	friend bool is_subset(const set& s1, const set& s2);
	// postcondition: returned whether s1 is a subset of s2

	friend bool operator == (const set& s1, const set& s2);
	// postcondition: returned whether s1 & s2 are equal

	friend std::ostream& operator << (std::ostream& output, const set& s);
	// postcondition: s has been displayed on output

private:
	size_type find(const value_type& entry) const;
	// returned location of entry in the set if entry is in the set - used otherwise
	value_type data[CAPACITY];
	size_type used;
};


#endif