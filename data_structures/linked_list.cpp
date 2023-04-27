
// linked list is better than arry in: flexible size - easy to add or delete items ,it doesn't allocate cosequetive places in memory but---it slowely access to items
// each node in the linked list is (variable:that carry data , pointer:that carry address to the next node) ..each node occupies two places in memory
//the first node in the linked lidt is only a pointer called head, the final node containn a variable and a pointer pointing to null (not poiting to any thing)
//
/*
note: I noticed that , with head node  we do not use (head->data) or (head->next).....so treat head as only a pointer the first node ...and it's used directly

    head=xnode means.that head will point to this node 
    head=xnode.next...means head will point to the node next to this node
*/

#include <iostream>
#include <string>
using namespace std;


struct node{
    int data;
    node* next; //what does this mean.......(the type of var next is node ???)
                //this pointer ~ points to a whole node

};

node* head =NULL; // global scope

void insert_node(int value){
    node * new_node = new node; // a pointer of type node that points to a place in the memory that has this allocated empty node
                                //why not (node new_node = new node)?????

    new_node->data=value;       // storing a value to the node using its reference 

    //at this point ,we have a node with value..this not is not connected to any thing in the memory

    node* last;                 // (a pointer to a node) will be used as a checker  .... it will check each node 


    if (head==NULL){            //if true (head not pointing to anything) then our node wil be the first node of the linked list...
        head = new_node;        //so we will make the head pointer to point to our node ( it will carry the address of our new node)..since new node is a pointer to a new node : there will be no problem to type head=new_node
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







void insert_begin(int value){
    node * new_node = new node; // a pointer of type node that points to a place in the memory that has this allocated empty node
    new_node->data=value;       // storing a value to the node using its reference 

    //at this point ,we have a node with value..this not is not connected to any thing in the memory
    new_node->next=head; // new node->next will points to th previous first node ..so that it takes its place          //note: if you use (new_node->next=head->next) the new node will replace the first node ??
    cout<<new_node->data<<endl;

    head=new_node; //making head points to our new node               //note: if you use (head->next=new_node) the inserted node will be the 2nd ??
    cout<<new_node->data<<endl;
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


// a function to delete_last node from  linked list 
//it will make the prevoius node points to the node that is next to the target node )make a pridge)...then deleting the target node
void delete_last (){

    node* current_node;     //this pointer will be used as a checker ..it will go through each node
    node* previous_node;   


    current_node=head;
    previous_node=head;

    //
    while (current_node->next!=NULL){   //if this node is not our target node

       //previous_node stand previous the current node
        previous_node=current_node; 
        current_node=current_node->next; //cuurent node move to next node

    } 
    previous_node->next=NULL;
    free(current_node); //deleting the current node from memory

    
        //cout<<current_node->data<<"\t"; //to print the value of the final node
 

};


void delete_begin (){

    node* current_node;     //this pointer will be used as a checker ..it will go through each node
    node*next_node; 


    current_node=head;
    next_node=head->next;

    head=next_node;
   //->next=NULL;
    free(current_node); //deleting the current node from memory

 

};







int main(){


    int list[]={22,34,55,66,67,68,99};

    for (int i : list)
        {insert_node(i);
        }
        

    //delete_last();
    //modify(21);
    //insert_begin(222);
    //delete_begin();
    insert_begin(100);

    display ();



 return 0;
};
