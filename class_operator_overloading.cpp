#include <iostream>
#include <string>
using namespace std;

class person{
	
	public:

		
	person (int money):	m(money)    // a constructor
	
	person operator+(person &obj){  //called operator overloadng to make calc between class objects
	    person sum;
	    sum.m=this->m + obj.m;          // (this)  an important word in operator overloading and provide access to object's own address ....this->var=var
	    return m;
	}
	

int main(){
	person p1(20);
	person p2(70);
    person p3(30) , p4(30);
	person sum=p1+p2+p3+p4; //is it possible to add many members or only 2
	cout<<sum.m<<endl;
	
}
