#include "myclass.h"
#include <iostream>
using namespace std;
#include <string>

//******* static variables must be created in global scope, outside the main function***********

MyClass::MyClass(){    // :: called scope resulotion operator and  used to define methods and variables that are previosly declared in the class in header file
};

//int MyClass:: var=3;
//const MyClass::var2=14; //this variable cannot be changed during the program

void MyClass::set_var (int x){
	this->var = x;	// like self in python ....will set member's var to x
};


void MyClass::sum(int a ,int b){
	
	cout<<a+b<<endl;
	
}


const int MyClass::cons() {		//constant function . constant object calls const function and vice verse , other than that an error will occuer
	
	cout<<"i'm consta'"<<endl;
}	
	
int main(){
	MyClass member;
	MyClass *ptr=&member;
	
	member.sum(1,5);
	ptr->sum(1,5);		// (-> = .) but first used with member pointer and 2nd used with member object itself to call its mehtods
	
	const MyClass member2;  // const can although be used with objects to make them and their variables constant during object life time
		
}	

	





