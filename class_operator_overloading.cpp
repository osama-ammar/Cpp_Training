#include <iostream>
#include <string>
using namespace std;
//.............error here.....................
class person{
	
	public:
	
	person (int money):	mo(money){
	};   // a constructor
	
	int mo;
	
	person operator+(person&obj) {  //called operator overloadng to make calc between class objects
	    person sum;
	    sum.mo=this->mo + obj.mo;          // (this)  an important word in operator overloading and provide access to object's own address ....this->var=var
	    return sum;
	}
};

int main(){
	person p1(20);
	person p2(70);
    person p3(30) , p4(30);
	person sum=p1+p2+p3+p4; //is it possible to add many members or only 2
	cout<<p1.mo<<endl;
	
}
