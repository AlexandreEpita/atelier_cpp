//
// Created by axcens on 28/02/23.
//

#include "list.hh"

#include <iostream>

List::List()
    : nb_elts_(0)
    , first_(nullptr)
    , last_(nullptr)
{}

void List::push_front(int i)
{
    if (nb_elts_ == 0)
    {
        first_ = std::make_shared<Node>(i);
        last_ = first_;
        nb_elts_++;
        return;
    }

    auto new_node = std::make_shared<Node>(i);
    first_->prev_set(new_node);
    new_node.get()->next_set(first_);
    first_ = new_node;
    nb_elts_++;
}

void List::push_back(int i)
{
    if (nb_elts_ == 0)
    {
        first_ = std::make_shared<Node>(i);
        last_ = first_;
        nb_elts_++;
        return;
    }

    auto new_node = std::make_shared<Node>(i);
    last_->next_set(new_node);
    new_node.get()->prev_set(last_);
    last_ = new_node;
    nb_elts_++;
}

std::optional<int> List::pop_front()
{
    if (first_ == nullptr)
        return std::nullopt;

    if (nb_elts_ == 1)
    {
        auto to_pop = first_;
        first_ = nullptr;
        last_ = nullptr;
        nb_elts_--;
        return std::optional<int>(to_pop.get()->val_get());
    }

    auto to_pop = first_;
    auto my_next = first_->next_get();
    my_next->prev_set(nullptr);
    first_ = my_next;
    nb_elts_--;
    return std::optional<int>(to_pop.get()->val_get());
}

std::optional<int> List::pop_back()
{
    if (last_ == nullptr)
        return std::nullopt;

    if (nb_elts_ == 1)
    {
        auto to_pop = first_;
        first_ = nullptr;
        last_ = nullptr;
        nb_elts_--;
        return std::optional<int>(to_pop.get()->val_get());
    }

    auto to_pop = last_;
    auto my_prev = last_->prev_get();
    my_prev->next_set(nullptr);
    last_ = my_prev;
    nb_elts_--;
    return std::optional<int>(to_pop.get()->val_get());
}

void List::print(std::ostream& os) const
{
    if (nb_elts_ == 0)
        return;
    auto my_head = first_;
    os << my_head->val_get();
    my_head = my_head->next_get();

    while (my_head != nullptr)
    {
        os << " " << my_head->val_get();
        my_head = my_head->next_get();
    }
}

int List::length() const
{
    return nb_elts_;
}