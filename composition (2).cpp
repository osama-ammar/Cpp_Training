#include <string>
#include <iostream>
using namespace std;

// means uusing exchanging functionality between classes
class Birth {
	public:		
	Birth(int d,int m,int y):
		day(d),month(m),year(y)     // like self.day=day......in python
		{
		}
	

	void printdate(){
		cout<<day<<"/"<<month<<"/"<<year<<endl;			
	}
	
	
	private:
		int day;
		int month;
		int year;	
	
};



class person{
	
	private:
		string name;
		Birth bd;
		int var=12;
		friend void modify(person &obj){    // this is called friend function -not a class member - used to access private members and modify them
		    obj.name="lion"
		    cout<<obj.name<<endl;
		}
	
	
	public:
	person(string n,Birth b):
		name(n),bd(b){
		}
		
	person (int money):	m(money)    // a constructor
	
	person operator+(person &obj){
	    person sum;
	    sum.m=this->m + obj.m;
	    return m;
	}
	
		
	void print_info(){
		cout<<name<<endl;
		bd.printdate();
					
	}
			
};



int main(){
	Birth bd(25,12,1994);
	person p("osama",bd);
	
	p.print_info();
	modify(p);
	
}




