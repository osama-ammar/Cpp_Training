// an object in oop has attribute(the current state of the object),identity,behavior(methods..what this object can do
//abstraction means providing only essential information to the outside world rather than how things work and implementation details
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
	private:
        string name;
        int regvar;
        const int constvar;
	
    public:    // called access specifier and may be (puplic,private(the default),protected)
    
        void sayHi() 
		{
            cout<<"Hi"<<endl;
        }
        
        void setname(string in) 
		{
            name=in;
        }
        
        void getname() 
		{
            cout<<name<<endl; //name or BankAccount::name
        }
        
        string title;
        
        /*BankAccount(){    //called by default when a member is added to the class...must have the same name of the class ...can contain a function as well
        	cout<<"I'm a constructor like __init__ in python"<<endl;  
        	string  get_title(string title){
           		 return title;
        	}        
        }*/
        
        ~BankAccount(){         // called destructor.opposite of constructor and called automatically when a member is destroyed -useful in releasindg memory and resources-
        }
        
        BankAccount(int a,const int b) : regvar(a),constvar(b) //initializing many types of variables
		{
		cout<<regvar<<endl;
		cout<<constvar<<endl;	
		}
};
//-------------------------------------------------------------------------------------------------------------------


int main(){
	
    BankAccount test(2,3);   //adding a member to the class
    test.sayHi();
    test.setname("agent1");
    test.getname();
    
    /*BankAccount test(3,8) ;
	test *ptr = &test;     //using a pointer to access the test's member
    ptr->sayHi();                  //to access the member's pointer methods use (->) operator.....//to access the member method use (.) operator
    ptr->setname("agent1");
    ptr->getname();*/
    
       
    return 0 ;
}


