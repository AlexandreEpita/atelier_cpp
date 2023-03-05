//
// Created by axcens on 28/02/23.
//

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#include "contact-details.hh"

class AddressBook
{
public:
    bool add(const std::string& full_name, const std::string& email,
             const std::string& number);
    std::vector<ContactDetails> find(const std::string& full_name);
    std::size_t count(const std::string& full_name);
    bool remove(const std::string& full_name, std::size_t index);
    void remove_all(const std::string& full_name);
    friend std::ostream& operator<<(std::ostream& os, const AddressBook& b);

private:
    std::multimap<std::string, ContactDetails> contacts_;
};

inline std::ostream& operator<<(std::ostream& os,
                                const AddressBook& addressBook)
{
    os << addressBook.contacts_.size() << " contact(s) in the address book.\n";
    for (std::pair<std::string, ContactDetails> elt : addressBook.contacts_)
    {
        os << "- " << elt.first << ": " << elt.second.number_ << ", "
           << elt.second.email_ << "\n";
    }
    return os;
}