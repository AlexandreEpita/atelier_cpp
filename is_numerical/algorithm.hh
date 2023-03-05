#pragma once

#include "is-numerical.hh"

template <typename T, typename = std::enable_if_t<is_numerical<T>::value>>
T algorithm(T number)
{
    return number;
}