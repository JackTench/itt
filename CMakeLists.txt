cmake_minimum_required(VERSION 3.15)

project(itt VERSION 1.0 LANGUAGES C CXX)

# Run the Python script to generate the dictionary header file.
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/dictionary.h
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/embed_dictionary.py
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/embed_dictionary.py
    COMMENT "Generating dictionary header file"
)
set_source_files_properties(
    src/main.cpp src/pwdgen.cpp
    PROPERTIES
    OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/dictionary.h
)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(itt 
    src/main.cpp
    src/pwdgen.cpp
    src/cat.c
    src/specs.cpp
)

set_target_properties(itt PROPERTIES
    C_STANDARD 99
    CXX_STANDARD 11
)