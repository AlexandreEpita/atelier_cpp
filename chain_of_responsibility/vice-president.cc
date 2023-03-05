//
// Created by axcens on 01/03/23.
//
#include "vice-president.hh"

#include <iostream>

void VicePresident::handle_request(int level)
{
    if (level <= 6)
        std::cout << "VicePresident handles\n";
    else
        this->forward_request(level);
}
