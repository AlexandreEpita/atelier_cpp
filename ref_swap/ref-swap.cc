//
// Created by axcens on 27/02/23.
//

#include "ref-swap.hh"

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}