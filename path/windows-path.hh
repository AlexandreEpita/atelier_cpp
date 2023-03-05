//
// Created by axcens on 28/02/23.
//

#pragma once

#include "path.hh"

class WindowsPath : public Path
{
public:
    WindowsPath(char root);
    std::string to_string() const override;
    Path& join(const std::string& tail, bool is_file = false) override;
};