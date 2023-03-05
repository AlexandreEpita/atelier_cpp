//
// Created by axcens on 28/02/23.
//

#pragma once

#include <cmath>
#include <iostream>

template <typename Iterator, typename Function>
Function my_foreach(Iterator first, Iterator last, Function f)
{
    for (auto it = first; it != last; ++it)
        f(*it);
    return f;
}