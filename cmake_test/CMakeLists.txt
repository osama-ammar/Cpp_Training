cmake_minimum_required(VERSION 3.22)

#name of the project
project(HelloWorld)


#we will make a variable called FilES_VAR that carry .cpp files names as values
set(FilES_VAR main.cpp src/math.cpp )

#making an executible called (Hello_executable) for main.cpp
#put here executible name and his .cpp files  
add_executable(Hello_executable  ${FilES_VAR} )




#if your .cpp files (Hello_executable) need files from a directory include this directory .... 
target_include_directories(Hello_executable PUBLIC include/)

message("this is my 1st message , .cpp files ${FILES_VAR} are added successfully")
message(STATUS "this is a normal status  message , building is running ... ")
message(WARNING "this is a warning message ")

# CMAKE_SOURCE_DIR is a variable related to cmake working parent dir  , it gives you the directerory tree path 
message("path offf cmake is ${CMAKE_SOURCE_DIR}")


#using if condition
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp )
    message(" main.cpp files already exists")
else()
    #this message type will stop building
    message(FATAL_ERROR "Cannot find main.cpp")
endif()

