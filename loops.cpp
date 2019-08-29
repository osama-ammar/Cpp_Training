
#include <iostream>
using namespace std;
int main()
{

int a=2;
int b=5;
int c=7;
int sum;

while(a<6)
{
 cout<<"a equals"<<a<<endl;
 a++;
}

while(b<8)
{
 cout<<"b equals"<<b<<endl;
 b++;
 cin >> sum ;
 c+=b;
}


cout<<"sum equals"<<sum<<endl;

for (int i = 0; i < 5; ++i)
{
 	cout<<"this is for loop";
}


do
{
	cout<<"this do while loop which guarantee to execute";
	cout<<"statments at least once regardless the condition met or not";
} while (b==90);

switch(b)	// used to test one expression with mutible cases
	{
	case 1 : 
		cout<<"case 1 met"<<endl;
		break;
	case 5 : 
		cout<<"case 2 met"<<endl;
		break;
	case 3 : 
		cout<<"case 3 met"<<endl;
		break;
	default :
		cout<<"this is the default case that";
		cout<<"is executed when none of cases meet ";	
	}


return 0;
}



