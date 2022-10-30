

//simple queue structure (first in first out)
// hard to add items after removing some items 
// simple queue structure is ----------empty: rear = front = -1    or front = rear+1
//                          -----------full : rear = size - 1


#include <string.h>
#include <iostream>
using namespace std;


#define size 5
int queue[size];
int front =-1 , rear=-1;

void enqueue(int value);
void dequeue();
void display();
int peek();











int main(){

    int list[]={1,2,3,4};
    for (int i:list){
        enqueue(i);
    }

    display();

    peek();

    dequeue();
    dequeue();

    peek();

    display();


    return 0;
}












void enqueue(int value){
    if(rear!=size-1){
        //queue can accept values
        queue[rear+1]=value;
        rear++;
        cout<<"an item is added : "<<value<<endl;


    }else{
        cout<<"queue is overflow"<<endl;
    }

    if(rear==0){front=0;}//
}










void dequeue(){
    if(rear==-1 && front>rear){cout<<"nothing to remove"<<endl;
    }else{
        cout<<"an item will be removed : "<<queue[front]<<endl;
        front++;

    }

}




int peek(){

    if(rear==-1 && front>rear){
        cout<<"nothing to show"<<endl;
        return -1;
    }else{
        cout<<"first item(customer) to be served now is : "<<queue[front]<<endl;
        return queue[front];
    }
}


void display(){
    if(rear==-1 && front>rear){
    cout<<"nothing to show"<<endl;
    }else{
        for (int i=front ; i<=rear ; i++){
            cout<<queue[i]<<endl;
            }
        }
}

