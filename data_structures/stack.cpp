//stack data structure (last in first out)
// ex (undo feature , stack memory)
// stack has one entry point .... push and pop from the same side 


#include <string.h>
#include <iostream>
#include <stack> // ready to use stack in stl 
using namespace std;

#define STACK_SIZE 5  //it will be global wether you define it globally or on a a name space 


namespace make_a_stack
{
        //used to define a constant value....
    int stack[STACK_SIZE];        //declaring a stack of STACK_SIZE
    int top=-1;             //this vaariable will be used to indicate the last value of the stack ....in this case it indicates an empty stack.


    int pop();
    void push(int value);
    int peek(int value);



    void push(int value){

        if (top == STACK_SIZE-1){
            cout<<"Stack Overflow"<<endl;
        }else{

            top++;
            stack[top]=value;

            cout<<"TOP = "<<top<<endl;
        }

    }

    int pop(){


        if (top == -1){
            cout<<"Stack underflow"<<endl;
            }else{
            cout<<"removed item is :"<<stack[top]<<endl;    

            cout<<"TOP after poping is = "<<top<<endl;

            return(top--);
            }
    }



    int peek(){


        if (top == -1){
            cout<<"Stack underflow"<<endl;
            }else{
            cout<<stack[top]<<endl; 
            return stack[top];   

            }
    };



    void display(){
        if (top == -1){
            cout<<"Stack underflow"<<endl;
        }else{ 
            for (int i=top; i>=0 ; i--){
                cout<<stack[i]<<endl;
            }  
        }
    }

}




// called by reference meaning that all actions here will directly affect the input ( not a copy of)
void show_stack(stack<int> in_stack)
{
    while (!in_stack.empty())
    {
        cout<<"top now is : "<<in_stack.top()<<endl;
        in_stack.pop();
    }
    cout<<endl;
}


int main()
{


    // push(11);
    // push(22);
    // push(33);
    // //for(int i : stack){cout<<i<<endl;}
    // //pop();
    // display();
    // peek();

    stack <int> mystack ;
    for (int i=0; i<10; i++)
        mystack.push(i);


    stack<int>  her_stack ; 
    for (int i=10; i<200; i+=30)
        her_stack.push(i);

    // me you and you me
    mystack.swap(her_stack);

    show_stack(her_stack);
    cout<<" my stack size is : " <<mystack.size()<<endl;


    return 0;
};







