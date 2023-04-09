
//composition:
// means using exchanging functionality between classes

// initialization in cpp
// int var1 = 1; copy initialisation 
// int var2(31); direct initialisation
// int var3{23}; uniform initialisation

/*
class is a user defined data type composed of  attributes , methods(behavior) , setters and getters
-attributes , methods etc are called class members
-anny function inside the class is inline function
-


this->   :  an automatically made pointer  for class attributes 


Run time polymorphism :
			- ocuuers in heap _ dynamic binding
			- dynamic : memory is altered or allocated during runtime (Run Riding)
			-ex) function overriding : where a function in parent and sons have same name && SIGNATURE (params no  , params type  )  but different behavior

Compile time polymorphism :
			-occuers in stack (static binding)
			- static : memory is altered or allocated only in compile time (compiLe Loading)
			-ex) function overloading : where a function in parent and sons have same name but DIFFERENT SIGNATURE (params no , params type
			-ex) operator overloading : giving an operator a meaning that works with class objects

*/

#include <iostream>
#include <string>
using namespace std;

class Person{
	
	private:
		string name;
		string birth_date;
		int mony;

        string outside_var;

		friend void modify(Person &obj)
		{    // this is called friend function -not a class member - used to access private members and modify them
		obj.name="lion";
		cout<<obj.name<<endl;
		}


	public:

		// // this method of initialisation is called initalisation list ?? 	
		// Person():
		// name("osama"),birth_date("12-12-2015"),mony(1556){}
		
		//constructor...note..name & _name
		Person(string _name="",string _birth_date="",int _mony=1000)
			{
			name = _name;
			birth_date = _birth_date;
			mony = _mony;
			};
		

		// this is called operator overloading like __add__ in python ?
		int operator+(Person &obj)
			{
			Person sum;
			sum.mony=this->mony + obj.mony;
			return sum.mony;
			}
		
	
		void print_info()
			{
			cout<<name<<endl<<birth_date<<endl<<mony<<endl;
			}

        //only declared method and will bw defined later outside the scope  of the class
        void set_outvar(string k);

		~Person(){ // called destructor.opposite of constructor and called automatically when a member is destroyed -useful in releasindg memory and resources-
		}
				
};

void Person::set_outvar(string k)
{
    //this->ourside_var=k;   ????
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
-encapsulation : to hide data - using access modifiers (public , private , protected)
-inheritance  : daughter class can use methods from barent class
-abstraction : using pure virtual methods(virtual int method_name =0 ) (abstract methods)
				daughter classes will override this virtual method 
-polymorphism :using pure or non pure virtual methods(virtual int method_name(){implementation} )
				parent class can use daughters' methods  that have the same name 
				polymorphism occuars in run time so it takes place in heap and initialized in heap

// an object in oop has attribute(the current state of the object),identity,behavior(methods..what this object can do
//abstraction means providing only essential information to the outside world rather than how things work and implementation details

//inheritance from base class doesn't include constructors and destructors.however they are called when making or deleting an object in derived class
// the base constructor is called first then derived constructor then derived destructor then base destructor
//polymorphism : single function with deferent implementations




*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






