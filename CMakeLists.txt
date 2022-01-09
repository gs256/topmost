cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
project(topmost LANGUAGES CXX)

add_executable(
    topmost 
    src/main.cpp 
    src/keyhook.cpp
    src/core.cpp
)