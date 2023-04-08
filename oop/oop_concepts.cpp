#include <iostream>
#include <string>
#include "oop_concepts.h"
#include "shape.h"
#include "animal.h"
#include "bank.h"
#include "author.h"
#include "date.h"
using namespace std;



int main(){

    // cat c1;
    // dog d1;   // const can although be used with objects to make them and their variables constant during object life time
    // c1.sayhi(); 
    // animal *a1 = &c1;   //since cat is daughter of animal we can do this
    // animal *a2 = &d1;
    // a1->set_colour("red");  //you can use [c1.set_colour("red");](directly without pointers) however pointers are faster 
    // a2->set_colour("yellow");
    

    // Circle cir(100) ;
    // Rectangle rec(5,7);
    // cout<<cir.getArea()<<endl;
    // cout<<rec.getArea()<<endl;
    // cin>>cir.radius>>"\n"

	// Person visitor("osama","12/12/2014",999994);
	// Person guest("kaomk","12/12/2024",444); 
	// visitor.print_info();
	// //modify(p);
	// int result = visitor+guest;
	// cout<<result<<endl;    


    Author * a1 = new Author("osama","osss@AI.com","male"); //initializing a pointer to an oblect class  in heap
    string auth_name=a1->getName();  
    cout<<auth_name<<endl;

    Book b1("the Life",150,3,*a1);
    Author y=b1.getAuthor();
    y.showInfo();

    // Account os("osama","1331",320000);
    // Account sho("shima","1911",1000);

    // os.credit(900);
    // os.debit(2900);
    // cout<<os.getBalance()<<endl;

    // os.transferMoney(sho,18000);
    // cout<<os.getBalance()<<endl;
    // cout<<sho.getBalance()<<endl;

    // Date today;
    // today.setDate(2004,12,12);
    // Time t1(9,59,59);

    // doing this will not affect t2 attributes it just take a copy of t1 and : 1-(will not update t2) 2-(update t1 only)
    //because the applied method (nextSecond) here is a t1 method not a t2 method
    // to solve this you should pass t1 to t2 by reference
    // 
    //Time t2=t1.nextSecond();  //==
    //cout<<t2.getHour()<<":"<<t2.getMinute()<<":"<<t2.getSecond()<<endl;



};













