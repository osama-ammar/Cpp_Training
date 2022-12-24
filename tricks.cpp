
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

//
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
    // when using static in declaration , a space for the variable is allocated during the life time of the progrsm
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
