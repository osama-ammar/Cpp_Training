// stack implementation using linked list

#include <string.h>
#include <iostream>
using namespace std;



struct Node {
    int value;
    Node *next;
};

int top=-1;
Node *head=NULL;

void insert(int value);
int delete_item();
void display();


int main(){


    insert(1);
    insert(2);
    insert(3);
    insert(4);
    display();
    delete_item();

    display();


    return 0;
}




void  insert(int value) {
    Node *new_node=new Node;
    new_node->value=value;

    if (head==NULL){

        top++;
        new_node->next=NULL;
        head=new_node;
        cout<<"new node (first in) is added : "<<new_node->value<<endl;

    }else{
        
        new_node->next=head; //if you reversed these two steps ..... it will be wrong...
        head=new_node;

        top++;
        cout<<"new node is added : "<<new_node->value<<endl;
    }

}


int delete_item(){

    if(head==NULL){
        cout<<"no items to delete (stack underflow"<<endl;
        return -1;
    }else{
        Node *first_node=head;
        head=first_node->next;
        top--;

        int var=first_node->value;
        cout<<"first node(last stack item) : "<< first_node->value<<"  is deleted"<<endl;
        delete(first_node); 
        return  var;
    }
}

void display (){

    Node* current_node;     //this pointer will be used as a checker ..it will go through each node

    if (head==NULL){        // if head is null..then it doesn't point to any think ..the linked list is empty
    cout <<"linked list is epmty"<<endl;
    }      
    else{                   //if head is is not empty..then it points to a node
        current_node=head;      //making the checker pointer to stand on (point to the  node that head points to now)

        //during this loop , the checker will go through every node and check it.
        while (current_node->next!=NULL){   //if this node is not the final node
            cout<<current_node->value<<"\t";     // prints its value
            current_node=current_node->next;    // put the checker on the next node
        } 
        cout<<current_node->value<<"\t"; //to print the value of the final node
    }

};

