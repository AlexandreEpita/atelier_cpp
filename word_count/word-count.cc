//
// Created by axcens on 27/02/23.
//

#include "word-count.hh"

#include <fstream>
#include <iostream>

ssize_t word_count(const std::string& filename)
{
    std::ifstream file_in;
    file_in.open(filename);
    if (!file_in.is_open())
        return -1;

    std::string word;
    ssize_t count = 0;
    while (file_in >> word)
        count++;

    file_in.close();
    return count;
}