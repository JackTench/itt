cmake_minimum_required(VERSION 3.15)

project(itt VERSION 1.0 LANGUAGES C)

# Run Python script to generate dictionary header.
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/dictionary.h
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/scripts/embed_dictionary.py
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/scripts/embed_dictionary.py
    COMMENT "Generating dictionary C header file."
)
set_source_files_properties(
    src/main.c
    PROPERTIES
    OBJECT_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/dictionary.h
)

add_executable(itt 
    src/main.c
    src/cat.c
)

set_target_properties(itt PROPERTIES
    C_STANDARD 99
)