
#include <iostream>
#include <string>
using namespace std;

template<class T,class G> //using of templates enables us make functions and classes accept many data types...Should be used


T sum(T a, T b){  //the same concept can be used in classes but when declaring  a function in the class and define it outside , [T classname<T>::fun(){some code}] the <T> should be used  
    return a+b;
    };
    
T bigger(T a, G b){ //we can use 2 different data types
    return (a>b ? a:b); //means if a>b return a ...else return b
    };    

class node{
    public:
        node(T a, T b):
            a(a),b(b){};
        
        
        T smaller(){
        return (a<b ? a:b);
        };
        
        T equal();
        
};

T node<T>::equal(){
        return (a=b ? a:b);
        };
    

int main(){
    int x=3,y=5;
    cout<<sum(x,y)<<endl;
    
    double n=33.7,m=51;
    cout<<sum(n,m)<<endl;
    
    cout<<bigger(x,n)<<endl;
    
    node <int> mem1(4,3); //member passed with  their types
    cout<<mem1.smaller()<<endl;
    
    node <double> mem2(4.5,32.2);
    cout<<mem1.smaller()<<endl;
    
    };
    
//////////////////////////////////////////////////////////////////////////////////////////////////////////    
class cat{
    cat(T x){
     cout<<x<<endl;   
    }
}    


template< > // template specialization....if the class member's type is char , the below code is executed ,other than this , the above will be executed
class cat<char>{
    cat(char x){
     cout<<x<<"I'm not x heh heh "<<endl;   
    }
}  

int main(){
    try{    //showing the exception
    
    int e1=3;
    int e2=6;
    if (e1<e2){throw 20} // code of error is 20 (or any thing you want )
    
    catch(int x){   //handling the exception    // read more about catch(...) 
       cout<<x<<"e1 is greater  "<<endl;  //this statement printed if error occur , x will be 20 ->num after throw
        }
    }
    
}




    
