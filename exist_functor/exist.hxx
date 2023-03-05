#pragma once
#include "exist.hh"

template <class T>
Exist<T>::Exist()
{
    all_values_saved = std::vector<T>();
}

template <class T>
bool Exist<T>::operator()(const T& elt)
{
    for (auto it = all_values_saved.begin(); it != all_values_saved.end(); ++it)
    {
        if (*it == elt)
            return true;
    }
    all_values_saved.push_back(elt);
    return false;
}