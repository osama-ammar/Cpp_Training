// there are two types of memory stack & heap ; Stack:managing memory on it is automatic , store local variables ,
//												heap::managing memory on it is manual , unused program memory that can be used when the program runs dynamically
// we cannot control life time in stack but we can do this in heap using new and delete operators.



#include <iostream>
#include <string>
using namespace std;
int main(){


int stackvar= 3;   //this lives in  stack 
int *ptrheap=new int(3);  // this lives in heap
//////////////////////////////////////////////////////////////////
// best practice

int* ptr_stackvar2 = new int(77);
//ptr_stackvar2 =& stackvar; 

delete ptr_stackvar2;
ptr_stackvar2 = nullptr;
/////////////////////////////////////////////////////////////////////////////

//nt *p= new int;   //by this expression we request (book) a memory location in heap using pointer and new
int *p=new int(3);              //we store a value in this location
cout<<*p<<endl;    // we use this value
delete p ;         //freeing up (heap) memory from this value using delete , but the pointer still not deleted ,So pointer is left pointing to non existing memoty location(dangling pointer)      

p=new int;          //reusing p for a new address

int *nptr= NULL;     //pointer of value of zero and still have no exact address to point to
nptr=new int[15];     //requesting (booking) a memory for an array  
delete [] p;          //deleting that array

cout<<sizeof(long int)<<endl; //give you the size of specific data type in your computer ..according to your coputer system and compiler used

///////////////////////////////////////////////////////////////////////////////////////////////////////
	// allocate memory for 20 integers (80 bytes)
	int * array = new int[20];

	cout << "The address of 'array' is " << &array << endl; /// every time you run this line we will get different results
	cout << "The value of 'array' is " << *array << endl;

	for ( int i = 0; i < 20; ++i ) {
		// cout << "The address of array[" << i << "] is " << &( array[i] ) << endl;
	}

	// must clean it up
	delete[] array;
	array = 0;









}










