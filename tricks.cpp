
#include <iostream>
#include <string>
using namespace std;
/*

to be searched for:
    namespace osama .........explain..........?????????
    var|=5     meaning
    FUNCTION OVERLOADING
    interleaved array

*/

/*
inline functions : C++ provides an inline functions to reduce the function call overhead
                    The overhead occures if the execution time of function is less than the switching time from the caller function to called function (callee)
                    using of inline function is good for small functions
                    it's just a request for the compiler , so the compiler may ignore this
                    - we ask the compiler to copy code into program rather than function call
                    - this saves time when calling a function ~ in normal case when you call a function in main , the compiler gooo toooo function definition and call it
                    -but in inline function ...the time for GOIING TOOO  the function definition is saved

                    ex) :
                        inline int cube(int s)
                            {
                                return s*s*s;
                            }


function overhead : Overhead is time spent not accomplishing useful work.
                    When you call a function, stuff needs to happen to jump to it,
                    then more stuff happens to go back to where you were. In the middle,
                    the content of your function is executed. The stuff that happens before and after is overhead



virtual function :A virtual function in C++ is a base class member function that you can redefine in a derived class to achieve polymorphism

*/

//    function recursion : any continous inside operations like in case of prime numbers

// pre processor directives (#) -------> dirct the preprocessor to ex) add extra code before compilations
/*
    # (macro directive)                     # define PRE 3
    # (file directive)                      # include <stdio.h> ....standard lib    or   # include "my_header.h".....user defined header
    # ( conditional compilation directive)  # ifdef-----endif
    # (special purpose directive)           # pragma startup/exit       These directives help us to specify the functions that are 
    needed to run before program startup                                                                        (before the control passes to main()) and just before program exit (just before the control returns from main()).
*/


/*
scope resolution operator (::)
1-C++ program to show that we can access a global variable
    using scope resolution operator :: when there is a local
    variable with same name

2-C++ program to show that scope resolution operator :: is
    used to define a function outside a class

3-C++ program to show that :: can be used to access static
    members when there is a local variable with same name

4-If the same variable name exists in two ancestor classes, 
we can use scope resolution operator to distinguish

5-If a class exists inside another class we can use the nesting class to refer
the nested class using the scope resolution operator
*/




// macro definiton : In the above program, when the compiler executes the word VARIABLE, it replaces it with 5.
// The word ‘LIMIT’ in the macro definition is called a macro template and ‘5’ is macro expansion.
#define VARIABLE 5
#define SUM (x, y)(x + y)

// conditional compilation directive : If the macro with the name ‘macro_name‘ is defined, then the block of statements will execute normally,
// but if it is not defined, the compiler will simply skip this block of statements.
#ifdef macro_name
cout << "will be " << endl;
cout << "applied " << endl;
#endif

// used you to undefine a macro ....... so logically after this statement in the code , (#ifdef LIMIT ) statements will not be executed because LIMIT is undefined
#undef LIMIT

// used to switch on/off features in the code ....... compiler specefic ....every compiler has its special purpose directive
//#pragma startup  osama::func    //this function will be excuted first
//#pragma exit    malek::func     //this function will be excuted the last, before the whole program ends

namespace osama
{
    void func()
    {
        cout << "namespace osama" << endl;
    }
    int var = 123321;
}

namespace malek
{
    void func()
    {
        cout << "namespace malek" << endl;
    }
}




void fun()
{
    // when using static in declaration , a space for the variable is allocated during the life time of the program
    // space FOR THE  variable is allocated ONCE only
    // the value of the variable in the prevoius function call is carried through the next call
    // the first oroginal value will be used once only in the first call
    static int var = 1;
    var++;
    cout << var << endl;
}



int var=5;  //global variable

int main()
{
    int var=23;  //local variable
    cout <<"local var is :"<<var<<"global  var is :"<<::var<<endl;

    for (int i = 0; i < 8; i++)
    {
        fun();
    }

    // cast operator to convert data type to another .....(int) variable.....
    float num = 2.3;
    int number1 = (int)num;
    // cout << number1 << endl;


    ////////////////////////////////////////////////////////////////////////////////////
    osama::func();
    malek::func();
    // cout << osama::var << endl;
    int iter = 2;

    ////////////////////////////////////////////////////////////////////////////////////////
    // ternary operator if (true)...result will be = passsed ................
    string result = (iter >= 40) ? "passed" : "failed";
    // can be nested
    result = (iter == 0) ? "Zero" : ((iter > 0) ? "Positive" : "Negative");
    ////////////////////////////////////////////////////////////////////////////////////

    return 0;
}
