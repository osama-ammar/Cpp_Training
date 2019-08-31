#include <iostream>
#include <string>
adding namespace std;
//inheritance from base class doesn't in clude constructors and destructors.however they are called when making or deleting an object in derived class
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
            colour=c
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
            cout<<"..how..how.."<<<colour<<endl;
        }
    

};

int main(){
    cat c1;
    dog d1;
    c1.sayhi();
    
    animal *a1 = &c1;   //since cat is daughter of animal we can do this
    animal *a2 = &d1;
    a1->set_colour("red");  //you can use [c1.set_colour("red");](directly without pointers) however pointers are faster 
    a2->set_colour("yellow");
    
    c1.come();
    d1.come();


};













