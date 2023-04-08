
// good practice for classes is to make 2 files the header (contain functions and variables declarations (prototypes)  and source file
#pragma once

#include <iostream>
#include <string>
using namespace std;



/*
abstracted class : classes that have at least one virtual pure method  
    -you cannot make objects from abstracted class
    -if the daughter class doesn't override the abstract method in the parent class then this daughter class become abstract class too 
*/
class Shape {
    //if ew tried to access this member variable - normally will give error
    //only seen inside the class not outside ( encapsulation)
    // usually all member variables are private and controlled by setters and getters (best practice)
    private:
        int mother_name ;

    protected:
        int height ; //ca be accessed only from a daughter class

    public:
        //constructors
        //we have 2 types of constructors : default and parameterized
        //constructors should be public
        //if you made a parameterized constructor , you should first create default constructor to avoid error
        Shape()
        {
            height =0;
        }

        //parameterized constructor
        Shape(int x)
        {
            // if you type (int height = x;) a new variable will be initialized and many problems will occccccccccccuers
            height = x;
        }


        //setters: starts with (set) followed with variable name 1stt capital , void 
        void setHight(int x)
        {
            height=x;
        }

        //getters
        int getHight()
        {
            return height ;
        }

        //virtal pure method : this method is written to be overriden by daughter classes and cannot be used directly
        // used to add abstraction to the class - normally parent class
        // we just say that a method called (getArea) will be used by the coming daughter classes
        virtual int getArea()=0; 


        //virtual non pure method : enable polymorphism
        // mean that parent object can call daughters method 
        //virtual int getArea()
        // {
        //     cout<<"shape Area :";
        //     return 0 ;
        // }



        //destructor is called automatically at the end of object lifecycle
        //you cannot have multiple destructors (cannot be overloaded)
        // used for memory release
        ~Shape(){

        }



};



class Circle : public Shape{
    public:
        int radius ;

        //constructors
        Circle (int x) : Shape(x)
        {
            radius = x;
        }

        //methods -- will override the getArea in parent class
        int getArea()
        {
            cout<<"circle Area :";
            return  radius*2*3.14;
        }

};


class Rectangle : public Shape{
    private:
        int width ;

    public:
        //constructors
        Rectangle(int x ,int y) :Shape(x)
        {
            width = y;
        }


        //setters
        void setWidth(int x)
        {
            width=x;
        }

        //getters
        int getWidth()
        {
            return width ;
        }

        //
        int getArea()
        {
            cout<<"Rectangle Area :";
            return width*height ;
        }

};

