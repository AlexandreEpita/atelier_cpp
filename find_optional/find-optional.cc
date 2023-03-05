//
// Created by axcens on 27/02/23.
//

#include "find-optional.hh"

#include <iostream>

std::optional<std::size_t> find_optional(const std::vector<int>& vect,
                                         int value)
{
    for (size_t i = 0; i < vect.size(); i++)
    {
        if (vect.at(i) == value)
            return std::optional(i);
    }

    return std::nullopt;
}