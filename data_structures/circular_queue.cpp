

//Circular queue structure (first in first out)
// easy to add items after removing some items 
// circular queue structure is ----------empty: rear = front = -1  --only
//                          -----------full : front=0 && rear= size-1     //  front=rear+1
//                           ---can accept value:  





#include <iostream>
#include <string>
using namespace std;




#define size 5
int queue[size];
int front =-1 , rear=-1;



bool isEmpty();
bool isFull();
void enqueue(int value);
void dequeue();
void display();
int peek();













int main(){

    int list[]={1,2,3,4,5};
    for (int i:list){
        enqueue(i);
    }

    display();

    dequeue();

    display();


    peek();


    dequeue();

    peek();

    display();


    return 0;
}









bool isEmpty(){
    if(front==-1 && rear==-1){
        return true;    
    }
    else{
        return false;
    }
}


bool isFull(){
    if(front==-1 && rear==size-1){
        return true;
    }
    else if(rear==front-1){
        return true;
    }
    else{
        return false;
    }
}



void enqueue(int value){

    if(isFull() )
    {cout<<"our circular queue is full"<<endl;
    }  
    else{
        if (isEmpty()){
            cout<<"queue is empty ... adding first value..."<<endl;
            front=rear=0;
            queue[rear]=value;
        }
        else if(rear==size-1){
            cout<<"queue is psudo full ... adding an item ..."<<endl;            
            rear=0;
            queue[rear]=value;
        }
        else{
            //adding one to rear ..then .. making queue[rear]=value
            cout<<"queue has places ... adding an item ..."<<endl;   
            queue[++rear]=value;
        }
    }
}





void dequeue(){
    if (isEmpty())
    {cout<<"nothing to remove"<<endl;
    }
    else{
        if (front==rear){// only one item in the queue
            front=rear=-1;
        }
        else if (front==size-1){
            rear=0;
        }
        else{
            front++;
        }
    }
}



int peek(){

    if(isEmpty()){
        cout<<"nothing to show"<<endl;
        return -1;
    }
    else{
        cout<<"first item(customer) to be served now is : "<<queue[front]<<endl;
        return queue[front];
    }
}




void display(){
    if(isEmpty()){
        cout<<"nothing to show"<<endl;
    }
    else{
        if (front <= rear){// like normal queue 
            for (int i=front ; i<=rear ; i++){
                cout<<queue[i]<<"\t";
                }
                cout<<endl;
        }
        else{// in this case the front is > rear , and we have to  mae 2 loops ..first to display frm front to the end (size-1)....second to display from queue begining (0) till rear index
            for (int i=front ; i<size ; i++){
                cout<<queue[i]<<"\t";
            }

            for (int i=0 ; i<=rear ; i++){
                cout<<queue[i]<<"\t";
            }
            cout<<endl;

        }
    }
}

