//
// Created by axcens on 27/02/23.
//

#include "int-container.hh"

MyIntContainer::MyIntContainer(size_t size)
    : current_size_(0)
    , max_size_(size)
    , elems_(std::make_unique<int[]>(size))
{}

void MyIntContainer::print() const
{
    if (current_size_ == 0)
        return;
    std::cout << elems_[0];
    for (size_t i = 1; i < current_size_; i++)
        std ::cout << " | " << elems_[i];
    std::cout << "\n";
}

size_t MyIntContainer::get_len() const
{
    return current_size_;
}

bool MyIntContainer::add(int elem)
{
    if (current_size_ + 1 > max_size_)
        return false;

    elems_[current_size_] = elem;
    current_size_++;
    return true;
}

std::optional<int> MyIntContainer::pop()
{
    if (current_size_ == 0)
        return std::nullopt;
    current_size_--;
    return elems_[current_size_];
}

std::optional<int> MyIntContainer::get(size_t position) const
{
    if (position >= current_size_)
        return std::nullopt;

    return elems_[position];
}

std::optional<size_t> MyIntContainer::find(int elem) const
{
    for (size_t i = 0; i < current_size_; i++)
    {
        if (elems_[i] == elem)
            return std::optional(i);
    }
    return std::nullopt;
}

void MyIntContainer::sort()
{
    int tmp;
    for (size_t i = 0; i < current_size_; i++)
    {
        for (size_t j = 0; j < current_size_ - i - 1; j++)
        {
            if (elems_[j] > elems_[j + 1])
            {
                tmp = elems_[j];
                elems_[j] = elems_[j + 1];
                elems_[j + 1] = tmp;
            }
        }
    }
}

bool MyIntContainer::is_sorted() const
{
    if (current_size_ <= 1)
        return true;

    for (size_t i = 0; i < current_size_ - 1; i++)
    {
        if (elems_[i] > elems_[i + 1])
            return false;
    }
    return true;
}