cmake_minimum_required(VERSION 3.22)

#name of the project
project(bank_system)

#setting c++ standard for this project
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED True)

#we will make a variable (~list) called FilES_VAR that carry .cpp files names as values
set(FilES_VAR 
    main.cpp
    src/bank_system.cpp )

set(PROJECT_PATH ${CMAKE_SOURCE_DIR})

message("cmake c++ standard is : ${CMAKE_CXX_STANDARD} , is required ? ${CMAKE_CXX_STANDARD_REQUIRED}")

#making executible and including needed files  
add_executable(bank_system  ${FilES_VAR} )

#if your .cpp files (Hello_executable) need files from a directory include this directory .... 
target_include_directories(bank_system PUBLIC  include/  lib/ )

