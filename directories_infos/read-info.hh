//
// Created by axcens on 27/02/23.
//

#pragma once

#include <fstream>
#include <iomanip>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

#include "directory-info.hh"

bool read_info(std::istream& input_file, DirectoryInfo& dir_info);