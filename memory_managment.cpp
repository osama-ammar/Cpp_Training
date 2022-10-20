// there are two types of memory stack & heap ; Stack:managing memory on it is automatic , store local variables ,
//												heap::managing memory on it is manual , unused program memory that can be used when the program runs dynamically

#include <iostream>
#include <string>
using namespace std;
int main(){

//nt *p= new int;   //by this expression we request (book) a memory location using pointer and new
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

	cout << "The address of 'array' is " << &array << endl;
	cout << "The value of 'array' is " << *array << endl;

	for ( int i = 0; i < 20; ++i ) {
		cout << "The address of array[" << i << "] is " << &( array[i] ) << endl;
	}

	// must clean it up
	delete[] array;
	array = 0;









}










