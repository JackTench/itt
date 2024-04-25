cmake_minimum_required(VERSION 3.15)

project(itt VERSION 1.0 LANGUAGES C)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(itt 
    src/main.c
    src/cat.c
)

set_target_properties(itt PROPERTIES
    C_STANDARD 99
)