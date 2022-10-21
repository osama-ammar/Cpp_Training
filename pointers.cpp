
#include <iostream>
#include <string>
using namespace std;


int main(){

int cat[]={2,33,442,43,33,22};
//int *ptrcat=nullptr;
//int *ptrcat=&cat;

int var=4;
int * ptrvar= &var;

// int *novar=var;   error ---not posssible (int* is considered a data type that only accept memory address)




cout << "ptrvar = " << ptrvar << endl;
cout << "*ptrvar = " << *ptrvar << endl;

// cout <<  "*ptrcat = " << *ptrcat << endl;


///////////////////////////////////////////////////////
char *charlist[]={"hellow world"};   // ypo can initialize pointers by this way with char type only
cout<< "charlist = " << charlist << endl;

return 0;
};



