
#include <iostream>
using namespace std;

template <class T>
T get_max(T a, T b)
{
    T max_num = (a > b) ? a : b;
    return max_num;
}

template <class T>
T swap_params(T a, T b)
{
    T temp = a;
    a = b;
    b = temp;
    return a, b;
}


template <class T>
class Calculator 
{
    public:


        //data members
        T data_member1;
        T data_member2;


        // methods
        T add(T a, T b)
        {
            return a + b;
        }

        T subtract(T a, T b)
        {
            return a -b;
        }


        T multiply(T a, T b)
        {
            return a * b;
        }


        T divide(T a,T b)
        {
            return a/b;
        }


        Calculator()
        {
            cout << " a new member has joined ";
        }

};








int main()
{

    // declaration
    int result;
    int a = 3;
    float b = 5.5;

    //constructor
    Calculator<int> perdon1;



    // operations
    result = get_max<float>(3, 5.5);


    a,b = swap_params<int>(a,b);



    // showing results
    cout << a << b << endl;

    return 0;
}