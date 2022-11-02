#include <iostream>
#include <string>
using namespace std;

/*

to be searched for:
    namespace osama .........explain..........?????????
    var|=5     meaning
    FUNCTION OVERLOADING
    interleaved arry


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
    static int var = 1;

    var++;
    cout << var << endl;
}

int main()
{

    for (int i = 0; i < 8; i++)
    {
        fun();
    }

    // cast operator to convert data type to another .....(int) variable.....
    float num = 2.3;
    int number1 = (int)num;
    cout << number1 << endl;

    osama::func();
    malek::func();
    cout << osama::var << endl;

    return 0;
}

/*
    shift+alt+A.......multible comment
    ctrl+/     line comment


 */
