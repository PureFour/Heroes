cmake_minimum_required(VERSION 3.9)
project(Heroes-Tests)

add_subdirectory(googletest)
add_executable(Fight_test Fight.cpp)