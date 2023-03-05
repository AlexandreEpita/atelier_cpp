//
// Created by axcens on 02/03/23.
//

#pragma once

#include "stack.hh"

template<class T>
Stack<T>::Stack(size_t max_size) : max_size_(max_size), stack_(std::vector<T>()) {}

template<class T>
Stack<T> &Stack<T>::push(const T &item) {
    stack_.push_back(item);
    return *this;
}

template<class T>
std::ostream & Stack<T>::print(std::ostream &s) const {

    if (stack_.empty())
        return s;

    s << *stack_.begin();
    for (auto it = stack_.begin() + 1; it != stack_.end(); ++it)
    {
        s << " " << *it;
    }
    return s;
}

template<class T>
typename std::vector<T>::const_reverse_iterator Stack<T>::begin() const{
    return stack_.rbegin();
}

template<class T>
typename std::vector<T>::reverse_iterator Stack<T>::begin() {
    return stack_.rbegin();
}

template<class T>
typename std::vector<T>::const_reverse_iterator Stack<T>::end() const{
    return stack_.rend();
}

template<class T>
typename std::vector<T>::reverse_iterator Stack<T>::end() {
    return stack_.rend();
}

template<class T>
void Stack<T>::resize(size_t t)
{
    if (t < max_size_)
    {
        for (size_t i = t; i < max_size_; i++)
            stack_.pop_back();
    }
    max_size_ = t;
}

template<class T>
size_t Stack<T>::max_size() const
{
    return max_size_;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const Stack<T>& p)
{
    if (p.begin() == p.end())
        return ostr;

    ostr << *p.begin();
    for (auto it = p.begin() + 1; it != p.end(); ++it)
    {
        ostr << " " << *it;
    }
    return ostr;
}

template<class T>
T Stack<T>::pop() {
    T value = stack_.back();
    stack_.pop_back();
    return value;
}

template <class T>
Stack<T> &Stack<T>::operator+=(T elt) {
    stack_.push_back(elt);
    return *this;
}

template <class T>
Stack<T> &Stack<T>::operator<<(T elt) {
    stack_.push_back(elt);
    return *this;
}

template <class T>
T Stack<T>::operator--() {
    return pop();
}

template <class T>
T Stack<T>::operator[](size_t t) {
    return *(stack_.begin() + t);
}

template <class T>
bool Stack<T>::operator==(Stack<T> other) {
    if (stack_.size() != other.stack_.size())
        return false;

    auto other_it = other.stack_.begin();
    for (auto it = stack_.begin(); it != stack_.end; ++it)
    {
        if (*it != *other)
            return false;
        other_it++;
    }
    return true;
}