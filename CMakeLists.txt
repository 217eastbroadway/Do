cmake_minimum_required(VERSION 3.10)

project(Do CXX)

set(BUILD "build")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD})

include_directories(include)
link_directories(lib)

set(SOURCES 
    src/main.cpp
    
)

add_executable(Do ${SOURCES})

target_link_libraries(Do PRIVATE raylib)
if(WIN32)
    target_link_libraries(Do PRIVATE opengl32 gdi32 winmm)
endif()