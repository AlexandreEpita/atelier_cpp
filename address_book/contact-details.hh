//
// Created by axcens on 28/02/23.
//

#pragma once

#include <iostream>

struct ContactDetails
{
    ContactDetails(const std::string& telephone_number,
                   const std::string& personal_email);
    std::string number_;
    std::string email_;

    friend std::ostream& operator<<(std::ostream& os, const ContactDetails& c);
};

inline std::ostream& operator<<(std::ostream& os, const ContactDetails& c)
{
    os << c.number_ << ", " << c.email_ << "\n";
    return os;
}