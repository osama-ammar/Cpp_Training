
// structure is a user defined data type tha tcan contain differet data types
// union looks like exactly the structure ..but...it stores only one member value which is the largest value

#include <iostream>
#include <string>
using namespace std;


struct Test{
    string name;
    int number; 
    int degree;

};

union Union_Test{
    string name;
    int number; 
    int degree;

};






int main(int argc, char** argv){

    // store a value (using pointers) that has not variable name
    int* ptr=new int(20); // this pointer points to value 20 ...this value has no name ( name of variable)...but we know the address of this value
    cout<<"ptr: "<<ptr<<endl;
    cout<<"*ptr: "<<*ptr<<endl;
    cout << "------------------" << endl;


    Test lolo;
    lolo.name = "abuza";
    lolo.number = 1564;
    cout << lolo.name << endl;
    cout << "------------------" << endl;



    Test *popo;
    popo->name = "abuza";
    popo->degree = 100;
    cout << popo << endl;
    cout << popo->name << endl;
    cout << "------------------" << endl;



    Test koko={"OSAMA",1481,97};
    cout << koko.number << endl;
    cout << "------------------" << endl;

    // making an arry of type test
    Test books[6];
    books[0].name = "habit labit";
    books[0].number = 12345;

    books[1].number = 989;

    cout << books[0].name << endl;
    cout << books[0].number << endl;
    cout << books[1].number << endl;
    cout << "------------------" << endl;








/*
    Union_Test uniko;
    uniko.name = "yoko";
    uniko.number = 6434;
    uniko.degree = 12;


    cout << uniko.name << endl;
    cout << uniko.number << endl;
    cout << uniko.degree << endl;
    cout << "------------------" << endl;
*/














    return 0;
};






