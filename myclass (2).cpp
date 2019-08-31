#include "myclass.h"
#include <iostream>
using namespace std;




MyClass::MyClass(){    // :: called scope resulotion operator and  used to define methods and variables that are previosly declared in the class in header file
};

int MyClass::var=3;
const MyClass::var2=14; //this variable cannot be changed during the program


int MyClass::sum(int a ,int b){
	g=a+b
	cout<<g<<endl;
}


void MyClass::cons() const{		//constant function . constant object calls const function and vice verse , other than that an error will occuer
	g=a+b
	cout<<g<<endl;
}	
	
int main(){
	MyClass member;
	MyClass *ptr=&member
	
	member.sum(1,5);
	ptr->sum(1,5)		// (-> = .) but first used with member pointer and 2nd used with member object itself to call its mehtods
	
	const MyClass member;  // const can although be used with objects to make them and their variables constant during object life time
		
}	

	





