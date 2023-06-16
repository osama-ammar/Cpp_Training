#include <iostream>
#include <string>
#include "include/bank_system.h"

/*
first build : 
            - make a build directory
            - in the build directory , run <cmake .. >   (going to dir where CMakeLists.txt exists and run cmake...this will generate some files in build)
            - run <cmake --build . --config Release >   (this will make a Release exe in build)
            - run the .exe file <.Release\bank.exe >

*/



int main()
{

    Client osos("osama",123,"1234azsd",3000);

    Client koko("koko",123,"1222zsd",3000);

    osos.check_balance();

    osos.transferMoney(koko , 1000);

    osos.check_balance();
    koko.check_balance();








    return 0;
}
