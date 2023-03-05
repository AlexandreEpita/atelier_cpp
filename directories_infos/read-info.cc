//
// Created by axcens on 27/02/23.
//

#include "read-info.hh"

bool read_info(std::istream& input_file, DirectoryInfo& dir_info)
{
    std::string line;
    if (!std::getline(input_file, line))
        return false;

    if (line.empty())
        return false;

    std::stringstream ss(line);

    if (!(ss >> dir_info.name_))
        return false;

    if (!(ss >> std::dec >> dir_info.size_))
        return false;

    if (!(ss >> std::oct >> dir_info.rights_))
        return false;

    if (!(ss >> dir_info.owner_))
        return false;

    if (ss >> line)
        return false;

    return true;
}