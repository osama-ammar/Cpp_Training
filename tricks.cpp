
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

//    function recursion : any continous inside operations like in case of prime numbers

// pre processor directives (#) -------> dirct the preprocessor to ex) add extra code before compilations
/*
    # (macro directive)                     # define PRE 3
    # (file directive)                      # include <stdio.h> ....standard lib    or   # include "my_header.h".....user defined header 
    # ( conditional compilation directive)  # ifdef-----endif
    # (special purpose directive)           # pragma startup/exit       These directives help us to specify the functions that are needed to run before program startup
                                                                        (before the control passes to main()) and just before program exit (just before the control returns from main()). 

*/




// macro definiton : In the above program, when the compiler executes the word VARIABLE, it replaces it with 5. 
//The word ‘LIMIT’ in the macro definition is called a macro template and ‘5’ is macro expansion.  
#define VARIABLE 5 
#define SUM (x,y) (x+y)

//conditional compilation directive : If the macro with the name ‘macro_name‘ is defined, then the block of statements will execute normally, 
//but if it is not defined, the compiler will simply skip this block of statements. 
#ifdef macro_name
    cout<<"will be "<<endl;
    cout<<"applied "<<endl;
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
    //the first oroginal value will be used once only in the first call
    static int var = 1;

    var++;
    cout << var << endl;
}


// looks like limited items data types
enum Shape
    {
        Circle,
        Square,
        Triangle,
        Oval,
        Polygon,
        NumShapes
    };


enum Landmarks
    {
        pognion=3,
        nasion=6,
        sella=9
    };





int main()
{

    for (int i = 0; i < 8; i++)
    {
        fun();
    }

    // cast operator to convert data type to another .....(int) variable.....
    float num = 2.3;
    int number1 = (int)num;
    //cout << number1 << endl;
////////////////////////////////////////////////////////////////////////////////////
    osama::func();
    malek::func();
    //cout << osama::var << endl;

    int iter=2;
//////////////////////////////////////////////////////////////////////////////////////
    //getting the index
    Landmarks land = (Landmarks)iter;
    cout<<"land mark : "<<land<<endl;

    //getting the value
    Landmarks prand = nasion;    
    cout<<"prand mark : "<<prand<<endl;

    //iterating through enum






////////////////////////////////////////////////////////////////////////////////////////
    //ternary operator if (true)...result will be = passsed ................
    string result = (iter >= 40) ? "passed" : "failed";
    //can be nested 
    result = (iter == 0) ? "Zero" : ((iter > 0) ? "Positive" : "Negative");
////////////////////////////////////////////////////////////////////////////////////



    return 0;
}


















/*
    shift+alt+A.......multible comment
    ctrl+/     line comment


 */
