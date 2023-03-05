#pragma once

#include "unordered-multimap.hh"

template <typename KeyType, typename ValueType>
bool UnorderedMultimap<KeyType, ValueType>::empty() const
{
    return unordered_multimap_.empty();
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::size() const
{
    return unordered_multimap_.size();
}

template <typename KeyType, typename ValueType>
std::pair<typename UnorderedMultimap<KeyType, ValueType>::iterator,
          typename UnorderedMultimap<KeyType, ValueType>::iterator>
UnorderedMultimap<KeyType, ValueType>::equal_range(const KeyType& key)
{
    auto begin = unordered_multimap_.begin();
    auto end = unordered_multimap_.end();
    while (begin != end && begin->first != key)
        ++begin;

    auto range_begin = begin;
    while (begin != end && begin->first == key)
        ++begin;

    return { range_begin, begin };
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::add(const KeyType& key,
                                                const ValueType& value)
{
    unordered_multimap_.emplace_back(key, value);
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::count(const KeyType& key) const
{
    unsigned count = 0;
    for (auto elt : unordered_multimap_)
    {
        if (elt.first == key)
            count++;
    }
    return count;
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::clear()
{
    unordered_multimap_.clear();
}
