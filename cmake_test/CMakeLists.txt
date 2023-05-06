cmake_minimum_required(VERSION 3.22)

#name of the project and its version
project(HelloWorld VERSION 11.12)

#we will make a variable (~list) called FilES_VAR that carry .cpp files names as values
set(FilES_VAR 
    main.cpp
    src/math.cpp )
# or you can do this 
set(FilES_VAR "main.cpp" ;  "src/math.cpp" )

#####################################################################################
#setting c++ standard for this project
set (CMAKE_CXX_STANDARD 14)
#if a library is running in other standard  , the following line will make in-compatability error
set (CMAKE_CXX_STANDARD_REQUIRED True)

################################################################################

#using if condition to check if a required file exists or not
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp )
    message(" main.cpp files already exists . continue building")
else()
    #this message type will stop building
    message(FATAL_ERROR "Cannot find main.cpp")
endif()
message("this is my 1st message , .cpp files ${FILES_VAR} are added successfully")
message(STATUS "this is a normal status  message , building is running ... ")
message(WARNING "this is a warning message ")
##################################################################################

# some cmake builtin variables
# cmake commands  can be written in upper case or lower case
# CMAKE_SOURCE_DIR is a variable related to cmake working parent dir  , it gives you the directerory tree path 
message("cmake c++ standard is : ${CMAKE_CXX_STANDARD} , is required ? ${CMAKE_CXX_STANDARD_REQUIRED}")
MESSAGE("path of CMAKE_SOURCE_DIR  is ${CMAKE_SOURCE_DIR}")
message("path of CMAKE_CURRENT_SOURCE_DIR  is ${CMAKE_CURRENT_SOURCE_DIR}")
MESSAGE("path of CMAKE_BINARY_DIR  is ${CMAKE_BINARY_DIR}")
MESSAGE("path of CMAKE_CURRENT_SOURCE_DIR  is ${CMAKE_CURRENT_SOURCE_DIR}")
message("path of CMAKE_GENERATOR is ${CMAKE_GENERATOR}")

####################################################################################################
#making executible and including needed files

#making an executible called (Hello_executable) for main.cpp
#put here executible name and corresponding .cpp files  
add_executable(Hello_executable  ${FilES_VAR} )

#if your .cpp files (Hello_executable) need files from a directory include this directory .... 
target_include_directories(Hello_executable PUBLIC  include/  lib/ )

########################################################################
# Adding a library an linking to it

#cmake will enter this directory which is a library and uses the CMakeLists inside it 
# ~ cmake inheritance
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

#linking our target(Hello_executable) to the  library we defined above (my library)
target_link_libraries(Hello_executable PUBLIC my_library)

#################################################################

set (my_env_variables $ENV{PATH})

# accessing env variables (  $ENV{}  )
#message(STATUS " env variables in this computer are : $ENV{PATH}")

#message( STATUS " my 1st env var is ${my_env_variables}")


########################################################################### 
# defining a variable in command line 
# by this command (  cmake .. -D my_new_variable=30  )

message("my new variable is ${my_new_variable}")


################################################################
# Configuration file 

set(RELEASE_YEAR "2022")

#generating a configuration file ( my_configuration.h) 
configure_file(defaultconfig.h.in  defaultconfig.h)

#because my_configuration.h will bw generated inside inside build , we should include PROJECT_BINARY_DIR dir so that our main can see it 
target_include_directories(Hello_executable PUBLIC  &{PROJECT_BINARY_DIR} )


##################################################################





