//
// Created by axcens on 27/02/23.
//
#include "stdin-to-file.hh"

#include <string>

void stdin_to_file()
{
    std::ofstream file_out;
    file_out.open("file.out");
    if (!file_out.is_open())
        return;

    std::string token;
    while (std::cin >> token)
        file_out << token << '\n';
}