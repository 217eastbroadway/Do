cmake_minimum_required(VERSION 3.10)

project(Do CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 5. Tell CMake where to look for your header files
# Now you can use #include "my_header.h" instead of #include "../include/my_header.h"
include_directories(include)

# 6. Gather your source files
# Best practice is to list them explicitly:
set(SOURCES 
    src/main.cpp
    # src/another_file.cpp 
)

add_executable(Do ${SOURCES})