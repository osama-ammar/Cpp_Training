#include <iostream>
#include <string>
using namespace std;


// whem using new operator, it should be used with a pointer ..and not a normal var...because new will allocate a block of memory in heap and this pointer 
// will be used to store the address of this block starting point 

class Node {
    public :
        int value;
        Node * next;

        Node (){
            this->value = 0;
            this->next = nullptr;            
        }

        Node(int value , Node * next){
            this->value = value;
            this->next = next;
        }

};


class LinkedList {

    Node * head;

    public:

    LinkedList() {
        head=nullptr;
    }

    void add_to_first(int value){

        //making a new node that points to (the head ) or (the first node in the linked list)
        Node * new_node = new Node(value,head);

        // making the head points to this new node
        head= new_node;
    }



    void remove_from_first()
    {
        // return here like -break- it will quit the function at this point 
        if (head == nullptr) return;

        head = head->next;
    }



    void add_to_last (int value)
    {
        Node * new_node = new Node(value,nullptr);

        if (head==nullptr)
        {
            cout<<" linked list is empty  , creating first node"<<endl;
            add_to_first(value);
            return;  
        }
        
        cout<<" linked list is not empty  , adding a node"<<endl;
        Node * checker = head;

        while (checker->next != nullptr)
        {
            checker =checker->next;

        }
        //checker=new_node; //if you do this , you  will replace the end node with the new node
        //adding a new node to the end of linked list
        checker->next=new_node;
                        cout<<" linked list is not empty  , adding a node"<<endl;
        }


    void remove_from_last ()
    {

        if (head==nullptr)
        {
            cout<<" linked list is empty ,quitting"<<endl;
            return;  
        }

        Node * checker = head;
        Node * deleter = head;
        while (checker->next != nullptr)
        {
            deleter =checker;
            checker =checker->next;

        }

        deleter->next=nullptr;
        delete checker;
    }


    void print()
    {
        Node * checker = head;
        while (checker->next != nullptr)
        {
            cout<<checker->value<<"-->";
            checker=checker->next;
        }        
        cout<<"nullptr"<<endl;
    }


};

////////////////////////////////////////////////////////////////////////////////////////////////
//  Functional implemenation of LinkedList 
////////////////////////////////////////////////////////////////////////////////////////////////

struct node{
    int data;
    node* next; //what does this mean.......(the type of var next is node ???)
                // this pointer will point to  data type node and exactly to the first member in this data type (which is data in this example)
                // 

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



