//
// Created by axcens on 28/02/23.
//

#include "windows-path.hh"

WindowsPath::WindowsPath(char root)
{
    std::string first = std::string("");
    first.push_back(root);
    first.append(":\\");
    path_.push_back(first);
}

std::string WindowsPath::to_string() const
{
    std::string res("");
    for (size_t i = 0; i < path_.size(); i++)
        res.append(path_.at(i));
    return res;
}

Path& WindowsPath::join(const std::string& tail, bool is_file)
{
    if (tail.find('\"') != std::string::npos
        || tail.find('|') != std::string::npos
        || tail.find('?') != std::string::npos
        || tail.find('*') != std::string::npos
        || tail.find(':') != std::string::npos)
        return *this;

    if (final_)
        return *this;
    if (is_file)
    {
        path_.push_back(tail);
        final_ = true;
    }
    else
    {
        path_.push_back(tail);
        path_.push_back(std::string("\\"));
    }
    return *this;
}