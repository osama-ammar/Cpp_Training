
// linked list is better than arry in: flexible size - easy to add or delete items ,it doesn't allocate cosequetive places in memory but---it slowely access to items
// each node in the linked list is (variable:that carry data , pointer:that carry address to the next node) ..each node occupies two places in memory
//the first node in the linked lidt is only a pointer called head, the final node containn a variable and a pointer pointing to null (not poiting to any thing)
//



#include <iostream>
#include <string>
using namespace std;


struct node{
    int data;
    node* next;

};

node* head =NULL; // global scope

void insert_node(int value){
    node * new_node = new node; // a pointer of type node that points to a place in the memory that has this allocated empty node
    new_node->data=value;       // storing a value to the node using its reference 

    //at this point ,we have a node with value..this not is not connected to any thing in the memory

    node* last;                 // (a pointer to a node) will be used as a checker  .... it will check each node 


    if (head==NULL){            //if true (head not pointing to anything) then our node wil be the first node of the linked list...
        head = new_node;        //so we will make the head pointer to point to our node ( it will carry the address of our new node)
        new_node->next=NULL;    //then we will terminate our list by making the next pointer to point to Null

    }else{
        last=head; // we will make (last pointer) to point to (head pointer) which points to a node
        while (last->next!=NULL) // if the (next) of (last) is not NULL , then this node is not the final node ..so we will 
        {
            last=last->next;      //make (last) points to the (next) of this node ...which is the address of the next node...we wil loop through nodes till we find the last one
        }

        // if last->next ==Null then this is the last node and we will append a node to it 
        last->next=new_node;
        new_node->next=NULL;

    //cout <<"last : "<< last <<  endl;
    //cout <<"head : "<< head <<  endl;

    }

};



// a function to display linked list content
void display (){

    node* current_node;     //this pointer will be used as a checker ..it will go through each node

    if (head==NULL){        // if head is null..then it doesn't point to any think ..the linked list is empty
    cout <<"linked list is epmty"<<endl;
    }      
    else{                   //if head is is not empty..then it points to a node
        current_node=head;      //making the checker pointer to stand on (point to the  node that head points to now)

        //during this loop , the checker will go through every node and check it.
        while (current_node->next!=NULL){   //if this node is not the final node
            cout<<current_node->data<<"\t";     // prints its value
            current_node=current_node->next;    // put the checker on the next node
        } 
        cout<<current_node->data<<"\t"; //to print the value of the final node
    }

};




// a function to delete a node from  linked list 
//it will make the prevoius node points to the node that is next to the target node )make a pridge)...then deleting the target node
void modify (int value){

    node* current_node;     //this pointer will be used as a checker ..it will go through each node
    node* previous_node;  


    current_node=head;
    previous_node=head;


    if (current_node->data==value){        // if value is in 1st node
        cout <<"our value is in 1st node and will be deleted"<<endl;
        
        head=current_node->next; //making the head pointing to the next node (the node that current node points to)
        free(current_node); //deleting the current node from memory
        return; //breaking the if statement
    }      

    //
    while (current_node->data!=value){   //if this node is not our target node

        previous_node=current_node;        //previous_node stand previous the current node 
        current_node=current_node->next; //cuurent node move to next node

    } 

    previous_node->next=current_node->next; ///whAT IF I TYPED ( previous_node=current_node->next;)
    free(current_node); //deleting the current node from memory

    
        //cout<<current_node->data<<"\t"; //to print the value of the final node
 

};






int main(){


    insert_node(33);
    insert_node(21);

    insert_node(32);
    insert_node(21);

    insert_node(38);
    insert_node(20);

    modify(21);
    display ();



 return 0;
};
