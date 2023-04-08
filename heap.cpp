#include <string>
#include <iostream>
using namespace std;


/*

heap::managing memory on it is manual , unused program memory that can be used when the program runs dynamically
		dynamic memory allocation
		VARIABLES are stored in random way
		accessed slowely and manually with pointers
		dynamic and large
		you need to delete unused variables



we cannot control life time in stack but we can do this in heap using new and delete operators.
*/


int main()
{

    int* p =NULL; // make a pointer in stack , to use it to point a var in heap
                  // because variables in heap has no names
    p=new int;  // request a space in heap var an integer variable and make the pointer points to it 

    *p=33;      // store a value in this variable
                // to conclude the previous 
                // int*p = new int (33);

    delete p ;  // delete the variable -in heap - that p points to 
                //but p still in the stack

    p = nullptr ; //zeroing the pointer in the stack

    ///////////////////////////////////////////////////////////////////////////////////////////
    /// array in heap ( use new d_type []  and delete [] )
    int size = 10 ; 
    int* p_arr= new int [size];
    delete [] p_arr ;

    return 0;
}



