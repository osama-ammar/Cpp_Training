#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>   // to take random function from it
using namespace std;


/*
E-difference between overloading and overriding?
-overloading : making functions valid for many datsa types
				here , we have 2 functions with the same name , but different  abilities
				we declare 2 functions in the same name but different parameters
				-compile time polymorphism
				-can be done in one class

-overriding : redifing a function \method with the same name and parameters 
				usually occuers in class inhertince , when child class override a parent method
				-run time polymorphism 
				-should be done in 2 classes
*/







void fun0(int a,int b,int c)   //by this method (assigning the arguments by value  we cannot make modification to the parameter ,we just take a copy of the variable and use it as an argument
	{
		int sum=a+b+c;
		cout<<sum<<endl;	
	}
	
void fun_ref(int *a) //by this method (assigning the arguments by reference -not value- we can make modification to the parameter, we take a copy of variable address and use it to access the variable itself in the memory..this saves memory rather than copying very large variable sizes
	{
		
		 * a=70;
		 cout<<*a<<endl;
		 	
	}

void fun_ref(int &a) //?????????????????????
	{
		
		a=70;
		cout<<a<<endl;
	}
	
int fun (float a,float b,float c) {  // this is called function overloading to make the same function valid for many types of inputs 
		float sum=a+b+c;
		cout<<sum<<endl;	
}
	
int factorial (int n){					//this is call recursion : making a function recall itself (figures for recursion and memory in c++)
		if (n==1){					// the exit condition (base case) important in recursion 
			return 1;
		}
		
		else {
			return n*factorial(n-1);
		}

};

/*void print_arr (int arr[],int size){	       //argument here is an array
		for (int i;x<size;x++){
			cout<<arr[i]<<endl;		
		}
	}*/
	
int main(){
	
	//srand(34) //if used  we will obtain a true random number tht will be produced every time you used the same seed
	//srand(time(0)) //if used  we will guarantee obtaining a true random number using the current time as a seed 
	// for (int i ;i<8;i++){
	// 	cout<<1+(rand()%10)<<endl; //psudo random number between 1 and 10
	// }	
		
	int var=3;
	fun_ref(&var);
	cout<<var<<endl;
	
	//fun(1,2,3);
	//fun(1.2,2.8,4.5);
	
	
	return 0;
};




