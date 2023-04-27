#include <iostream>
using namespace std;


/*
make : a program that understands Makefile and executes the rules int it 

Makefile : contains rules & commands to be execured

cmake : a program that understands CMakeList file and executes the rules int it 

CMakeList : contains commands simpler than those written in Makefile
            used by cmake to generate make files for your project



(cmake -G "MinGW Makefiles" ..) : cmake will generate Makefiles  for your project based on instructions you type in CMakeLists
                                    these generated files will be proper for MinGW generator (you can select your favorite generator)

                                    if you type make in command  , the executible will be generated



*/

int main()
{
    cout << " Hello I'm make , cmake , makelist..........."<<endl;
}