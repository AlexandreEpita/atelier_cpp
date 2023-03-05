//
// Created by axcens on 27/02/23.
//

#include "invalid-argument.hh"

InvalidArgumentException::InvalidArgumentException(const std::string& msg)
    : msg_(msg)
{}

const char* InvalidArgumentException::what() const noexcept
{
    return msg_.data();
}