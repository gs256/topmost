cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(topmost LANGUAGES CXX)
add_definitions(-DNOUNICODE)

add_executable(
    topmost 
    WIN32
    src/winmain.cpp 
    src/keyhook.cpp
    src/core.cpp
)