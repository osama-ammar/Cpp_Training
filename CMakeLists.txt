#Version of the operating system. Generally the kernel version.
cmake_minimum_required(VERSION 3.0.0)

#name of your project version
project(cpp_training VERSION 0.1.0)

#
include(CTest)
enable_testing()

#to build main.cpp
add_executable(cpp_training main.cpp)

#
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
