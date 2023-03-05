//
// Created by axcens on 02/03/23.
//
#include "auction.hh"

Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
    , nft_(std::move(nft))
    , highest_bidder_(nullptr)
    , highest_bid_(initial_bid)
{
    if (nft_ == nullptr)
        throw std::invalid_argument("Auction: the nft is empty!");
}

Auction::~Auction()
{
    if (highest_bidder_ == nullptr)
    {
        organizer_.add_nft(create_nft(*nft_.get()));
        return;
    }
    highest_bidder_->add_nft(std::move(nft_));
    organizer_.add_money(highest_bid_);
}

bool Auction::bid(Person& person, uint money)
{
    if (money <= highest_bid_)
        return false;

    if (highest_bidder_ == nullptr)
    {
        if (!person.remove_money(money))
            return false;

        highest_bidder_ = &person;
        highest_bid_ = money;
        return true;
    }

    if (!person.remove_money(money))
        return false;

    highest_bidder_->add_money(highest_bid_);
    highest_bid_ = money;
    highest_bidder_ = &person;
    return true;
}

std::string Auction::get_nft_name() const
{
    return *nft_.get();
}

uint Auction::get_highest_bid() const
{
    return highest_bid_;
}
