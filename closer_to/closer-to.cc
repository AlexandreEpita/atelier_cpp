//
// Created by axcens on 28/02/23.
//

#include "closer-to.hh"

#include <algorithm>
#include <iostream>
#include <vector>

CloserTo::CloserTo(int i)
    : i_(i)
{}

bool CloserTo::operator()(const int& a, const int& b) const
{
    if (abs(i_ - a) == abs(i_ - b))
    {
        if (a <= b)
            return true;
        else
            return false;
    }

    if (abs(i_ - a) > abs(i_ - b))
        return false;
    else
        return true;
}