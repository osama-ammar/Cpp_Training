#include <string>
#include <iostream>
using namespace std;


//composition:
// means uusing exchanging functionality between classes

// initialization in cpp
// int var1 = 1; copy initialisation 
// int var2(31); direct initialisation
// int var3{23}; uniform initialisation


class person{
	
	private:
		string name;
		string birth_date;
		int mony;


		friend void modify(person &obj)
		{    // this is called friend function -not a class member - used to access private members and modify them
		obj.name="lion";
		cout<<obj.name<<endl;
		}


	public:

		// // this method of initialisation is called initalisation list ?? 	
		// person():
		// name("osama"),birth_date("12-12-2015"),mony(1556){}
		
		//constructor...note..name & _name
		person(string _name="",string _birth_date="",int _mony=1000)
			{
			name = _name;
			birth_date = _birth_date;
			mony = _mony;
			};
		

		// this is called operator overloading like __add__ in python ?
		int operator+(person &obj)
			{
			person sum;
			sum.mony=this->mony + obj.mony;
			return sum.mony;
			}
		
	
		void print_info()
			{
			cout<<name<<endl<<birth_date<<endl<<mony<<endl;
			}
				
};



int main(){

	person visitor("osama","12/12/2014",999994);

	person guest("kaomk","12/12/2024",444);

	visitor.print_info();
	//modify(p);

	int result = visitor+guest;
	cout<<result<<endl;
	
}




