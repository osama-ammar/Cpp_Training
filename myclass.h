// good practice for classes is to make 2 files the header (contain functions and variables declarations (prototypes)  and source file
#ifndef MYCLASS_H  //if not defined 	//  called conditional compilation  directive
#define MYCLASS_H  // define			//  called macro directive

#include <iostream>
#include <string>
using namespace std;

//composition:
// means uusing exchanging functionality between classes

// initialization in cpp
// int var1 = 1; copy initialisation 
// int var2(31); direct initialisation
// int var3{23}; uniform initialisation


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

// an object in oop has attribute(the current state of the object),identity,behavior(methods..what this object can do
//abstraction means providing only essential information to the outside world rather than how things work and implementation details

//inheritance from base class doesn't include constructors and destructors.however they are called when making or deleting an object in derived class
// the base constructor is called first then derived constructor then derived destructor then base destructor
//polymorphism : single function with deferent implementations
class animal{
    public: //can be accessed any where
        animal(){};
        void sayhi(){
            cout<<"I'm an animal"<<endl;
            }
        string colour;  
        void set_colour(string c){
            colour=c;
        }; 
        
        virtual void come(){};   //good implementation to add this , it tells you that the derived class may have this function . if[virtual void come()=0](pure virtual function) then,derived functions should have this function name
                                 //this function can contain implementaion here and used as poly morphic function
                                 //in case you use pure virtual function then the class will not accept to have members but can be inherited only
    
    private:    //can be accessed by friend method
        void priv(){
            cout<<"I'm a private animal"<<endl;
            }
        
   protected:   //can be accessed from the derived class
        void protec(){
            cout<<"I'm a protected animal"<<endl;
            } 
    
};


class cat:public animal{    //by this way we inherit from animal class -inherit public and protected methods not private methods...the inherited methods become public in this class
                            // ..if we write private or protected rather than public the inherited methods become private or protected in this class
    public:
        cat(){};
        void come(){
            cout<<"..naw..naw.."<<colour<<endl;
            
        }  
};

class dog:public animal{
                        
    public:
        dog(){};
        void come(){
            cout<<"..how..how.."<<colour<<endl;
        }
};

#endif //MYCLASS_H













