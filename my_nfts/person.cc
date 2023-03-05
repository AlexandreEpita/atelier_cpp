//
// Created by axcens on 02/03/23.
//

#include "person.hh"

Person::Person(const std::string& name, uint money)
    : name_(name)
    , money_(money)
    , nfts_(std::vector<NFT>())
{}

std::vector<std::string> Person::enumerate_nfts() const
{
    auto my_enum = std::vector<std::string>();
    for (auto it = nfts_.begin(); it != nfts_.end(); ++it)
        my_enum.push_back(*it->get());
    return my_enum;
}

void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}

NFT Person::remove_nft(const std::string& name)
{
    for (auto it = nfts_.begin(); it != nfts_.end(); ++it)
    {
        if (*it->get() == name)
        {
            NFT to_remove = std::move(*it);
            nfts_.erase(it);
            return to_remove;
        }
    }
    return create_empty_nft();
}

void Person::add_money(uint money)
{
    money_ += money;
}

bool Person::remove_money(uint money)
{
    if (money > money_)
        return false;
    money_ -= money;
    return true;
}

uint Person::get_money() const
{
    return money_;
}

std::string Person::get_name() const
{
    return name_;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << "\n"
       << "Money: " << p.get_money() << "\n";
    os << "NFTs:";

    auto vec = p.enumerate_nfts();
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        os << " " << *it;
    }
    return os << "\n";
}