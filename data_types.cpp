
/* data types
integers : (33,5,-4) ...size of integer depends on the archticture of the 
			system on which your program runs ..min size of modern systems 
			archticture is 4 bytes.
floats : (3.4,-5.0) have 3 types (always signed)
		float:4 bytes in most systems
		double: 8 bytes
		long double: 8 or 16 bytes
strigs : "man" , "n"
characters : 'm','a','%','*'  ..holds 1 byte character
boolean: holds 2 values 1 (True) or 0 (False)
 

type modifiers: modify some data types like integers
		signed:signed integer can hold negative or positive numbers
		unsigned:unsigneed integer can hold only positive numbers
		short :half the default size
		long :twice the default size





*/
#include <iostream>
#include <string>
using namespace std;
int main(){

unsigned long int a=2;
//cout<<a<<endl;

unsigned long int *ip; //declaration and definition  of a pointer, (pointer is a variable that holds the memory address of another variable ,its type is according to variable it points to )
float * fb;
string*sb;

ip=&a;

cout<<a<<endl<<ip<<endl<<*ip<<endl;




int arr[4]={1,2,3,4};

int arrb[]={1,2,3,4,5,6,7,8,9,10};
int sum=0;

for (int i=0;i<3;i++){
	arr[i]=i*2;
	sum+=i;	
}
//out<<arr<<endl<<arrb<<endl<<arr[6]<<endl<<sum<<endl;

int arr2d[3][3]={
{1,2,3},
{4,5,6},
{7,8,9}
};
//cout<<arr2d[1][1]<<sizeof(arr2d)<<<<endl; //sizeof gives the size of the array in bytes and cab be used to give no of elements of the array !!!!
}






















