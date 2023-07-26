cmake_minimum_required(VERSION 3.22)

#name of the project
project(bank_system)

######################################################
######################################################

#setting c++ standard for this project
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_STANDARD_REQUIRED True)

#we will make a variable (~list) called FilES_VAR that carry .cpp files names as values
set(FilES_VAR 
    main.cpp
    src/bank_system.cpp )

set(PROJECT_PATH ${CMAKE_SOURCE_DIR})
set(DATA_PATH "D:/Code_store/Cpp_Training/Bank_Project/data")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDATA_PATH")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DDATA_PATH")
######################################################
######################################################

message("cmake c++ standard is : ${CMAKE_CXX_STANDARD} , is required ? ${CMAKE_CXX_STANDARD_REQUIRED}")
message("project path ${CMAKE_SOURCE_DIR}")
message("DATA_PATH    ${DATA_PATH} ")

######################################################
######################################################

#making executible and including needed files  
add_executable(bank_system  ${FilES_VAR} )

#if your .cpp files (Hello_executable) need files from a directory include this directory .... 
target_include_directories(bank_system PUBLIC  include/  lib/ )

#adding DATA_PATH to be identified ... and used 
target_compile_options(bank_system PUBLIC -DMY_PATH=${DATA_PATH})

# this ~enable you to define Databath in cpp files as a macro
#target_compile_definitions(bank_system PUBLIC ${DATA_PATH})

# Create a target to run the project from vscode button
add_custom_target(run
  COMMAND ${CMAKE_COMMAND} -E echo "Running my_project..."
  COMMAND ./bank_system
)

# Set the default target to run
set_target_properties(run PROPERTIES FOLDER "Run")
######################################################
######################################################



#set(DATA_PATH "D:/Code_store/Cpp_Training/Bank_Project/data")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -${DATA_PATH}")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -${DATA_PATH}")

#adding DATA_PATH to be identified ... and used 
#target_compile_options(bank_system PUBLIC -DMY_PATH=${DATA_PATH})

# this ~enable you to define Databath in cpp files as a macro
#target_compile_definitions(bank_system PUBLIC ${DATA_PATH})


####################
# Configuration
####################

#generating a configuration file ( my_configuration.h) 
#configure_file(defaultconfig.h.in  defaultconfig.h)


#because my_configuration.h will bw generated inside inside build , we should include PROJECT_BINARY_DIR dir so that our main can see it 
# target_include_directories(bank_system PUBLIC  &{PROJECT_BINARY_DIR} )
# target_compile_definitions(bank_system
# 	PUBLIC
# 		-DDATA_PATH="${DATA_PATH}"
# )

