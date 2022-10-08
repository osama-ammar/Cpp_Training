
#include <iostream>
#include <string>
using namespace std;


// an object in oop has attribute(the current state of the object),identity,behavior(methods..what this object can do
//abstraction : means providing only essential information to the outside world rather than how things work and implementation details



class BankAccount {
    public:    // called access specifier and may be (puplic,private(the default),protected)
        void sayHi() {
            cout<<"Hi"<<endl;
        };
        
        string title;
        


        string  get_title(){
            return title;
            cout<<title<<endl;
        	}
        	
       string  get_name(){
            return name;
        	} 	
        
        BankAccount(){    //called by default when a member is added to the class...must have the same name of the class ...can contain a function as well
        	cout<<"I'm a constructor like __init__ in python"<<endl;  
                	
        }
        
        ~BankAccount(){         // called destructor.opposite of constructor and called automatically when a member is destroyed -useful in releasindg memory and resources-
        }
        
    private:
        string name;

};
//-------------------------------------------------------------------------------------------------------------------


int main(){
    BankAccount test;   //adding a member to the class
    test.sayHi();
    test.title="agent1";
    test.get_title();
    
    //BankAccount test *ptr = &test;     //using a pointer to access the test's member

    //ptr->.sayHi();                  //to access the member's pointer methods use (->) operator.....//to access the member method use (.) operator

    //ptr->.title='agent1';
    
    //test.name="osos";   //this gives an error because name here is private ...cannot be accessed directly

    //test.get_name();
    //string myname = test.get_name();
    
    cout<<test.title<<endl;

    //cout<<myname<<endl;
    
    return 0 ;
};


