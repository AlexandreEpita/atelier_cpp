//
// Created by axcens on 27/02/23.
//

#include "replace.hh"

#include <fstream>
#include <iostream>
#include <string>

void replace(const std::string& input_filename,
             const std::string& output_filename, const std::string& src_token,
             const std::string& dst_token)
{
    std::ifstream file_in;
    std::ofstream file_out;

    file_in.open(input_filename);
    if (!file_in.is_open())
    {
        std::cerr << "Cannot open input file\n";
        return;
    }

    file_out.open(output_filename);
    if (!file_out.is_open())
    {
        std::cerr << "Cannot write output file\n";
        return;
    }

    std::string word;
    size_t pos;
    while (std::getline(file_in, word))
    {
        pos = 0;
        while (word.find(src_token, pos) != std::string::npos)
        {
            pos = word.find(src_token, pos);
            word.replace(pos, src_token.length(), dst_token);
            pos += dst_token.length();
        }
        file_out << word << '\n';
    }
    file_in.close();
}