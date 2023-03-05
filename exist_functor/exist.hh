#pragma once

#include <vector>

template <class T>
class Exist
{
public:
    Exist();
    bool operator()(const T& elt);

private:
    std::vector<T> all_values_saved;
};

#include "exist.hxx"
