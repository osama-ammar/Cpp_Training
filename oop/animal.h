
// good practice for classes is to make 2 files the header (contain functions and variables declarations (prototypes)  and source file
#ifndef MYCLASS_H  //if not defined 	//  called conditional compilation  directive
#define MYCLASS_H  // define			//  called macro directive

#include <iostream>
#include <string>
using namespace std;


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

