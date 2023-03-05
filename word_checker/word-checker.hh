//
// Created by axcens on 02/03/23.
//

#pragma once

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class WordChecker
{
public:
    WordChecker(const std::string file_name);

    bool operator()(const std::string& elt);

private:
    std::string file_name_;
};
