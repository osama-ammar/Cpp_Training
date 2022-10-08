
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

#include <iomanip> // to use setprecision


using namespace std;
int main(){

unsigned long int a=2;
//cout<<a<<endl;

unsigned long int *ip; //declaration and definition  of a pointer, (pointer is a variable that holds the memory address of another variable ,its type is according to variable it points to )
float * fb;
string *sb;

ip=&a;

//cout<<a<<endl<<ip<<endl<<*ip<<endl;




int arr[4]={1,2,3,4};

int arrb[]={1,2,3,4,5,6,7,8,9,10};
int sum=0;

for (int i=0;i<8;i++){
	arr[i]=i*2;
	//cout<<arr[i]<<endl;
	sum+=i;	
}
cout<<arr<<endl<<arrb<<endl<<arr[6]<<endl<<sum<<endl;

int arr2d[3][3]={
{1,2,3},
{4,5,6},
{7,8,9}
};

//cout<<arr2d[1][1]<<sizeof(arr2d)<<<<endl; //sizeof gives the size of the array in bytes and cab be used to give no of elements of the array !!!!



/*

precision of 4 bytes is 7
/////////// of 8 bytes .....is 8 and so so

*/


short int osshort=12;

long long int oslong=12;

float osfloat=1.255125555555332311111111;

double osdouble=1.255125555555332311111111L;

cout<<"size of arr2d is : "<<sizeof(arr2d)<<" bytes"<<endl;

cout<<"size of osshort is : "<<sizeof(osshort)<<" bytes"<<endl;

cout<<"size of oslong is : "<<sizeof(oslong)<<" bytes"<<endl;

cout<<"size of osfloat is : "<<sizeof(osfloat)<<" bytes"<<endl;


cout<<std::setprecision(4);

cout<<"size of osdouble is : "<<sizeof(osdouble)<<" bytes"<<endl;

cout<<" osdouble is : "<<osdouble<<" as seen the precision is not as we declare it , it's decreased due to the type this variable is stored with"<<endl;


}






















