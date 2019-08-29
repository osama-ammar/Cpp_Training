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
	
	
	public:
	person(string n,Birth b):
		name(n),bd(b){
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
	
}




