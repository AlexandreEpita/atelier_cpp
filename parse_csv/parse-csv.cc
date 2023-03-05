//
// Created by axcens on 28/02/23.
//

#include "parse-csv.hh"

std::vector<std::vector<std::string>> parse_csv(const std::string& file_name)
{
    std::vector<std::vector<std::string>> my_csv;
    std::ifstream input_file;
    input_file.open(file_name);
    if (!input_file.is_open())
        throw std::ios_base::failure("Error opening file");

    std::string line;
    std::string word;
    int nb_word_in_oneline = -1;
    int i;
    int line_count = 1;
    while (std::getline(input_file, line))
    {
        std::vector<std::string> vec;
        std::istringstream ss(line);
        if (nb_word_in_oneline == -1)
        {
            nb_word_in_oneline = 0;
            while (std::getline(ss, word, ','))
            {
                nb_word_in_oneline++;
                vec.push_back(word);
            }
            if (word.empty())
            {
                nb_word_in_oneline++;
                vec.push_back(std::string(""));
            }
        }
        else
        {
            i = 0;
            while (std::getline(ss, word, ','))
            {
                i++;
                vec.push_back(word);
            }

            if (word.empty())
            {
                i++;
                vec.push_back(std::string(""));
            }

            if (i != nb_word_in_oneline)
                throw std::ios_base::failure(
                    "Non consistent number of columns at line "
                    + std::to_string(line_count));
        }
        my_csv.push_back(vec);
        line_count++;
    }
    return my_csv;
}