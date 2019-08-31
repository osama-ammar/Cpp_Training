// an object in oop has attribute(the current state of the object),identity,behavior(methods..what this object can do
//abstraction means providing only essential information to the outside world rather than how things work and implementation details
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
    public:    // called access specifier and may be (puplic,private(the default),protected)
        void sayHi() 
		{
            cout<<"Hi"<<endl;
        }
        
        string title;
        
        BankAccount(){    //called by default when a member is added to the class...must have the same name of the class ...can contain a function as well
        	cout<<"I'm a constructor like __init__ in python"<<endl;  
        	string  get_title(string title){
           		 return title;
        	}        
        }
        
        ~BankAccount(){         // called destructor.opposite of constructor and called automatically when a member is destroyed -useful in releasindg memory and resources-
        }
        
        BankAccount(int a,int b)	//initializing many types of variables
		: regvar(a),constvar(b){
		cout<<regvar<<endl;
		cout<<constvar<<endl;	
		}
        
    private:
        string name;
        int regvar;
        const int constvar;

};
//-------------------------------------------------------------------------------------------------------------------


int main(){
    BankAccount test;   //adding a member to the class
    test.sayHi();
    test.name="agent1";
    
    BankAccount test *ptr = &test;     //using a pointer to access the test's member
    ptr->.sayHi();                  //to access the member's pointer methods use (->) operator.....//to access the member method use (.) operator
    ptr->.name="agent1";
    
    cout<<test.name<<endl;
    
    BankAccount test(2,3); 
    
    return 0 ;
};


