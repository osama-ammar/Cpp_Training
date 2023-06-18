#include <iostream>
#include <string>
#include "include/bank_system.h"

/*
first build : 
            - make a build directory
            - in the build directory , run <cmake .. >   (going to dir where CMakeLists.txt exists and run cmake...this will generate some files in build)
            - run <cmake --build . --config Release >   (this will make a Release exe in build)
            - run the .exe file <.\Release\bank_system.exe >

*/
// a static member in clent class.... set to zero here (only zeroed outside the class)
int Client::count=0;

int main()
{

    Client osos("osama",75123,"1234azsd",3000,12222);
    Client koko("koko",34123,"1222zsd",3000,3455);
    Employee employee("mohsen ahmed", 6456, "pass123",4200,6000,5000);
    Admin sayed ("sayed hanafy", 3434, "pass123",8100,12000,15000);

    osos.check_balance();
    osos.transferMoney(koko , 1000);
    osos.check_balance();
    koko.check_balance();

    double employee_new_slary;
    cout << "set emplyee new salary ......."<<endl;
    cin >> employee_new_slary;
    sayed.set_employee_salary(&employee,employee_new_slary);
    osos.transferMoney(koko , 1000);
    osos.check_balance();
    koko.check_balance();





    return 0;
}
