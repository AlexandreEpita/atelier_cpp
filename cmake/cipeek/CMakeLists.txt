cmake_minimum_required(VERSION 3.21.2)

project(atelier_c++)

add_executable(cipeek src/cipeek.cc)
target_compile_options(cipeek PRIVATE -Wall -Wextra -Werror -pedantic)

find_library(YAML NAMES yaml-cpp REQUIRED)

target_link_libraries(cipeek PRIVATE ciutils)
target_link_libraries(ciutils PRIVATE ${YAML})

set_target_properties(cipeek PROPERTIES
        CXX_STANDARD 20
        CXX_EXTENSIONS OFF
        )