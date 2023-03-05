//
// Created by axcens on 28/02/23.
//

#include "unix-path.hh"

std::string UnixPath::to_string() const
{
    std::string res = "/";
    for (size_t i = 0; i < path_.size(); i++)
        res.append(path_.at(i));
    return res;
}

Path& UnixPath::join(const std::string& tail, bool is_file)
{
    if (final_)
        return *this;
    if (is_file)
    {
        path_.push_back(tail);
        final_ = true;
    }
    else
        path_.push_back(tail + "/");

    return *this;
}
