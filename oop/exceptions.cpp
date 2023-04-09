#include <iostream>
#include <exception>
#include <string>
using namespace std;
/*
Exception handling using polymorphism
the parent class (exception) takes the shape of its sons according to the error


*/


class ZeroException : public exception
{
    public:
        const char* what() const throw()
        {
            return "cannot devide by zero";
        }
        
};

class NegativeException : public exception
{
    public:
        const char* what() const throw()
        {
            return "cannot devide by negative no";
        }
        
};

void devide(float x, float y)
{
    if (y==0)
    {
        throw ZeroException();
    }

    else if (y < 0){
        throw NegativeException();
    }

    else{
    cout<< "x/y = "<<x/y<<endl; 
    }
}

int  main()
{

    float x,y;
    cin>>x>>y;
    try{
        devide(x,y);
    }
    catch(exception &e){
        cout<<e.what()<<endl;
    }
}







