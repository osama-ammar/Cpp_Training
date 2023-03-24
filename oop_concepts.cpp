#include <iostream>
#include <string>
#include "myclass.h"
using namespace std;



int main(){
    cat c1;
    dog d1;
    c1.sayhi();
    
    animal *a1 = &c1;   //since cat is daughter of animal we can do this
    animal *a2 = &d1;

    a1->set_colour("red");  //you can use [c1.set_colour("red");](directly without pointers) however pointers are faster 
    a2->set_colour("yellow");
    
    c1.come();
    d1.come();


	// Person visitor("osama","12/12/2014",999994);
	// const Person guest("kaomk","12/12/2024",444); // const can although be used with objects to make them and their variables constant during object life time
	// visitor.print_info();
	// //modify(p);
	// int result = visitor+guest;
	// cout<<result<<endl;    



};













