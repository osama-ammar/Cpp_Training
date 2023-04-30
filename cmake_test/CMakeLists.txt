cmake_minimum_required(VERSION 3.22)

#name of the project
project(HelloWorld)


#we will make a variable called FilES_VAR that carry .cpp files names as values
set(FilES_VAR main.cpp src/math.cpp )


#using if condition to check if a required file exists or not
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp )
    message(" main.cpp files already exists . continue building")
else()
    #this message type will stop building
    message(FATAL_ERROR "Cannot find main.cpp")
endif()




#making an executible called (Hello_executable) for main.cpp
#put here executible name and his .cpp files  
add_executable(Hello_executable  ${FilES_VAR} )

#if your .cpp files (Hello_executable) need files from a directory include this directory .... 
target_include_directories(Hello_executable PUBLIC  include/  lib/ )



message("this is my 1st message , .cpp files ${FILES_VAR} are added successfully")
message(STATUS "this is a normal status  message , building is running ... ")
message(WARNING "this is a warning message ")
# CMAKE_SOURCE_DIR is a variable related to cmake working parent dir  , it gives you the directerory tree path 
message("path of cmake working dir  is ${CMAKE_SOURCE_DIR}")

#cmake will enter this directory which is a library and uses the CMakeLists inside it 
# ~ cmake inheritance
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

#linking our target(Hello_executable) to the  library we defined above (my library)
target_link_libraries(Hello_executable PUBLIC my_library)

