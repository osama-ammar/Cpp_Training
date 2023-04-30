#include <iostream>
#include "math.hpp"  //our program is linked to this file by cmake

#include "module.hpp" //our program is linked to this file by cmake

using namespace std;


/*
make : a program that understands Makefile and executes the rules in it 

Makefile : contains rules & commands to be executed



cmake : a program that understands CMakeList file and executes the rules int it 

CMakeList : contains commands simpler than those written in Makefile
            used by cmake to generate make files for your  c/c++  project



(cmake -G "MinGW Makefiles" ..) : cmake will generate Makefiles  for your project based on instructions you type in CMakeLists
                                    these generated files will be proper for MinGW generator (you can select your favorite generator)

                                    if you type make in command  , the executible will be generated
                                    so to conclude the steps :
                                        1-cmake reads cmakelists and generate make file
                                        2- we use make to build this make file to generate the executable



*/

int main()
{

    int x ;
    x = sum(4,6);

    cout << " Hello I'm make , cmake , makelist......"<<x<<"....."<<G;

    cout<<endl;

    // this function is located inside my_library .... which is a library linked to my code  using cmake
    wifi_init();
}