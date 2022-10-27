
#include <string.h>
#include <iostream>
using namespace std;


#define size 5          //not closed expression ?
int stack[size];        //
int top=-1;             //


void pop();
void push(int value);
int peek(int value);



void push(int value){

    if (top == size-1){
        cout<<"Stack Overflow"<<endl;
    }else{

        top++;
        stack[top]=value;

        cout<<"TOP = "<<top<<endl;
    }

}

void pop(){


    if (top == -1){
        cout<<"Stack underflow"<<endl;
        }else{
        cout<<"removed item is :"<<stack[top]<<endl;    
        top--;
        cout<<"TOP after poping is = "<<top<<endl;
        }
}



int peek(){


    if (top == -1){
        cout<<"Stack underflow"<<endl;
        }else{
        cout<<stack[top]<<endl; 
        return stack[top];   

        }
}



void display(){
    if (top == -1){
        cout<<"Stack underflow"<<endl;
    }else{ 
        for (int i=top; i>=0 ; i--){
            cout<<stack[i]<<endl;
        }  
    }
}




int main()
{


    push(11);
    push(22);
    push(33);

    //for(int i : stack){cout<<i<<endl;}

    //pop();

    display();

    peek();

    //for(int i : stack){cout<<i<<endl;}






    return 0;
};







