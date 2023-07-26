#include <iostream>
#include <string>
#include <cstdio>

#include "include/bank_system.h"
#include "include/data_files.h"

/*
first build : 
            - make a build directory
            - in the build directory , run <cmake .. CMakeLists.txt >  this line go step behind build to read cmakelist and generate build files inside build
            - run <cmake --build . --config Release >   (this will make a Release exe in build)
            - run the .exe file <.\Release\bank_system.exe >

*/
// a static member in client class.... set to zero here (only zeroed outside the class)
int Client::count=0;

int main()
{
    std::cout << "I'mmmmmmmm eworkkking" <<endl;

    Client osos("osama",75123,"1234azsd",3000,12222);
    Client koko("koko",34123,"1222zsd",3000,3455);
    Employee employee("mohsen ahmed", 6456, "pass123",4200,6000,5000);
    Admin sayed ("sayed hanafy", 3434, "pass123",8100,12000,15000);
    std::cout << "I'mmmmmmmm eworkkking" <<endl;

    // FileManager data_source;
    // data_source.addClient(osos);
    // data_source.addClient(koko);
    // data_source.addAdmin(sayed);

    //getchar();

    osos.check_balance();
    osos.transferMoney(koko , 1000);
    osos.check_balance();
    koko.check_balance();
    std::cout << "I'mmmmmmmm eworkkking" <<endl;

    double employee_new_slary;
    cout << "set emplyee new salary ......."<<endl;
    cin >> employee_new_slary;
    sayed.set_employee_salary(&employee,employee_new_slary);
    osos.transferMoney(koko , 1000);
    osos.check_balance();
    koko.check_balance();
    std::cout << "I'mmmmmmmm eworkkking" <<endl;





    return 0;
}
