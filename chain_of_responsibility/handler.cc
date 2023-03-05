//
// Created by axcens on 01/03/23.
//
#include "handler.hh"

#include <iostream>

Handler::Handler(Handler* next)
    : next_(next)
{}
void Handler::set_successor(Handler* h)
{
    next_ = h;
}
void Handler::forward_request(int level)
{
    if (level <= 9 && next_ != nullptr)
    {
        next_->handle_request(level);
        return;
    }
    std::cout << "Nobody can handle this request\n";
}
