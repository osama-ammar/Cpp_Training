cmake_minimum_required(VERSION 3.22)

message(STATUS "Hello , I'm a new library here......")


#making module.cpp and module.hpp as library .. soo that we can use it later by another proramms
add_library(my_library #library name
            module.cpp
            module.hpp)