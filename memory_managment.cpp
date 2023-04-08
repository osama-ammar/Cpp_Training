
#include <iostream>
#include <string>
using namespace std;


/*
there are two types of memory stack & heap ;
Stack:managing memory on it is automatic 
		static memory allocation
		VARIABLES are stored in arranged way
		accessed fast
		limited and fixed

heap::managing memory on it is manual , unused program memory that can be used when the program runs dynamically
		dynamic memory allocation
		VARIABLES are stored in random way
		accessed slowely and manually with pointers
		dynamic and largy
		you need to delete unused variables



we cannot control life time in stack but we can do this in heap using new and delete operators.
*/



void triple (int * var)
{
	*var *=3;
}

void ref_triple (int var)
{
	var *=3;
}



int main(){

//////////////////////////////////////////////////////////////////
//                 Stack
//////////////////////////////////////////////////////////////////

// int stackvar= 3;   //this lives in  stack 
// int cat[]={2,33,442,43,33,22};
// int var=4;

// int* kom =nullptr; //initialize a pointer that does not point to anything 
// 					//the correct way of  initializing a new pointer
// cout << "kom = " << kom << endl;
// //cout << "*kom = " << *kom << endl;
// cout << "&kom = " << &kom << endl;

// int * ptrvar= &var;
// // int *novar=var;   error ---not posssible (int* is considered a data type that only accept memory address)
// cout << "ptrvar = " << ptrvar << endl;
// cout << "*ptrvar = " << *ptrvar << endl;
// printf("my name is %d ,%s",4,"osama");

//////////////////////////////////////////////////////////////////
//                 Heap
//////////////////////////////////////////////////////////////////


//int *p= new int;   //by this expression we request (book) a memory location in heap using pointer and new
// int *p=new int(3);              //we store a value in this location
// cout<<*p<<endl;    // we use this value
// delete p ;         //freeing up (heap) memory from this value using delete , but the pointer still not deleted ,So pointer is left pointing to non existing memoty location(dangling pointer)      

// p=new int;          //reusing p for a new address

// int *nptr= NULL;     //pointer of value of zero and still have no exact address to point to
// nptr=new int[15];     //requesting (booking) a memory for an array  
// delete [] p;          //deleting that array

//cout<<sizeof(long int)<<endl; //give you the size of specific data type in your computer ..according to your coputer system and compiler used

//////////////////////////////////////////////////////////////////////////////////
//   							Arryas
/////////////////////////////////////////////////////////////////////////////////

//using cout differs from printf
int arr[] {0,1,2,3,4,5,6};

cout<<"arr : "<<arr<<endl; // arr is consider a pointer to the array
printf("*arr = %d\n",*arr);
printf("arr[1] = %d\n",arr[1]);
cout<<"arr : "<<arr<<endl;
printf("======================== \n");

int *parr = arr;
cout<<"parr : "<<parr<<endl;
printf("parr[1]  = %d\n",parr[1]);
cout<<"parr+1 : "<<parr+1<<endl;


// allocate memory for 20 integers (80 bytes)
int * array = new int[20];
//cout << "The address of 'array' is " << &array << endl; /// every time you run this line we will get different results
//cout << "The value of 'array' is " << *array << endl;
for ( int i = 0; i < 20; ++i ) {
	// cout << "The address of array[" << i << "] is " << &( array[i] ) << endl;
}

// must clean it up
delete[] array;
array = 0;
	return 0;

}










