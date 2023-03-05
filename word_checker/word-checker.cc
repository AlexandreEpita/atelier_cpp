//
// Created by axcens on 02/03/23.
//

#include "word-checker.hh"

WordChecker::WordChecker(const std::string file_name)
    : file_name_(file_name)
{}

bool WordChecker::operator()(const std::string& elt)
{
    std::ifstream file_in;
    file_in.open(file_name_);

    std::string word;
    if (elt.size() == 1)
    {
        while (file_in >> word)
        {
            if (word.size() == 1 && word.compare(elt) == 0)
                return true;
        }
        return false;
    }

    bool find;
    std::vector<std::string> vec = std::vector<std::string>();
    while (file_in >> word)
    {
        vec.push_back(word);
    }
    for (size_t i = 0; i < elt.size() - 1; i++)
    {
        find = false;
        std::string pair = "";
        pair.push_back(elt.at(i));
        pair.push_back(elt.at(i + 1));
        for (auto it = vec.begin(); it != vec.end(); ++it)
            if (it->find(pair) != std::string::npos)
            {
                find = true;
                break;
            }
        if (!find)
            return false;
    }
    return true;
}