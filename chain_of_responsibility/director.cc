//
// Created by axcens on 01/03/23.
//
#include "director.hh"

#include <iostream>

void Director::handle_request(int level)
{
    if (level <= 3)
        std::cout << "Director handles\n";
    else
        this->forward_request(level);
}
