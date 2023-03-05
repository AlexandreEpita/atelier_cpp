//
// Created by axcens on 28/02/23.
//

#include "contact-details.hh"

ContactDetails::ContactDetails(const std::string& telephone_number,
                               const std::string& personal_email)
{
    for (char c : telephone_number)
    {
        if (!std::isdigit(c))
        {
            throw std::invalid_argument("Incorrect number.");
        }
    }

    int count = 0;
    for (char c : personal_email)
    {
        if (c == '@')
            count++;
    }

    if (count != 1)
        throw std::invalid_argument("Incorrect email.");

    number_ = telephone_number;
    email_ = personal_email;
}