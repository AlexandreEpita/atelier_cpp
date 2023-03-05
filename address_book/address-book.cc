//
// Created by axcens on 28/02/23.
//

#include "address-book.hh"

bool AddressBook::add(const std::string& full_name, const std::string& email,
                      const std::string& number)
{
    if (full_name.empty() || email.empty() || number.empty())
        return false;

    try
    {
        contacts_.insert(std::pair<std::string, ContactDetails>(
            full_name, ContactDetails(number, email)));
        return true;
    }
    catch (const std::invalid_argument& e)
    {
        return false;
    }
}

std::vector<ContactDetails> AddressBook::find(const std::string& full_name)
{
    std::vector<ContactDetails> res;
    for (std::pair<std::string, ContactDetails> elt : contacts_)
    {
        if (elt.first.compare(full_name) == 0)
            res.push_back(elt.second);
    }
    return res;
}

std::size_t AddressBook::count(const std::string& full_name)
{
    std::size_t res = 0;
    for (std::pair<std::string, ContactDetails> elt : contacts_)
    {
        if (elt.first.compare(full_name) == 0)
            res++;
    }
    return res;
}

bool AddressBook::remove(const std::string& full_name, std::size_t index)
{
    if (index >= contacts_.size())
        return false;

    std::multimap<std::string, ContactDetails>::iterator it;
    for (it = contacts_.begin(); it != contacts_.end(); it++)
    {
        if (it->first.compare(full_name) == 0)
        {
            if (index != 0)
                index--;
            else
            {
                contacts_.erase(it);
                return true;
            }
        }
    }
    return false;
}

void AddressBook::remove_all(const std::string& full_name)
{
    contacts_.erase(full_name);
}
