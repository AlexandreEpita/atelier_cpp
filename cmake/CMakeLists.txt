cmake_minimum_required(VERSION 3.21.2)

project(atelier_c++)

add_library(ciutils SHARED src/ciutils.cc) #lib + ciutils + .so
target_compile_options(ciutils PRIVATE -Wall -Wextra -Werror -pedantic)

target_include_directories(ciutils PUBLIC include/) # path des .hh

add_subdirectory(cipeek) #dans le dossier build le binaire

set_target_properties(ciutils PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        )