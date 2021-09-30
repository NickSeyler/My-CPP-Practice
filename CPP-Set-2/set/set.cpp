//Author:   Nick Seyler
//Date:     2/7/17
//File:     set.cpp

#include "set.h"
#include <cassert>
#include <iostream>

set::set()
{
    used = 0;
}

void set::insert(const value_type& entry)
{
    if (find(entry) == used)
    {
        assert(used < CAPACITY);
        data[used] = entry;
        used++;
    }
    else
        return;
}

void set::remove(const value_type& entry)
{
    if (find(entry) != used)
    {
        data[find(entry)] = 0;
        used--;
    }
}

set::size_type set::size() const
{
    return used;
}

bool set::contains(const value_type& entry) const
{
    if (find(entry) != used)
        return true;
    else
        return false;
}

set set_union(const set& s1, const set& s2)
{
    set s3;

    for (int i = 0; i < s1.used; i++)
        s3.insert(s1.data[i]);

    for (int i = 0; i < s2.used; i++)
        s3.insert(s2.data[i]);

    return s3;
}

set set_intersection(const set& s1, const set& s2)
{
    set s3;

    for (int i = 0; i < s1.used; i++)
        if (s2.find(s1.data[i]) != s2.used)
            s3.insert(s1.data[i]);

    return s3;
}

set set_difference(const set& s1, const set& s2)
{
    set s3;

    for (int i = 0; i < s1.used; i++)
        if (s2.find(s1.data[i]) == s2.used)
            s3.insert(s1.data[i]);

    return s3;
}

bool is_subset(const set& s1, const set& s2)
{
    for (int i = 0; i < s1.used; i++)
        if (s2.find(s1.data[i]) == s2.used)
            return false;

    return true;
}

bool operator == (const set& s1, const set& s2)
{
    if (s1.size() != s2.size())
        return false;
    else
    {
        for (int i = 0; i < s1.used; i++)
            if (s2.find(s1.data[i]) == s2.used)
                return false;

        return true;
    }
}

std::ostream& operator << (std::ostream& output, const set& s)
{
    for (int i = 0; i < s.used; i++)
        output << s.data[i] << " ";

    return output;
}

set::size_type set::find(const value_type& entry) const
{
    for (int i = 0; i < used; i++)
        if (data[i] == entry)
            return i;

    return used;
}