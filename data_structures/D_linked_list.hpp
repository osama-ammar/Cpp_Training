#include <iostream>
#include <string>
using namespace std;




class Node {
    public:
        int value ;
        Node * previous ;
        Node * next ; 


        Node(Node * previous ,int value ,Node * next ){
            this->previous=nullptr;
            this->value=0;
            this->next=nullptr;
        }

};





class DLinkedList{

    public:
        Node * head ;
        Node * tail ;


        DLinkedList (){
            head = nullptr;
        }


        void add_to_start(int value){
            Node * new_node= new Node(nullptr,value,nullptr) ;

            if (head==nullptr){
                cout<<"dlist is empty ..adding 1st node..."<<endl;
                head=new_node;
                new_node->next=nullptr;
                return;
            }  
            new_node->next=head;
            head=new_node;


        }




        void add_to_last(int value){
            Node * new_node ;
            new_node->value=value;

            if (head==nullptr){
                cout<<"dlist is empty ..adding 1st node..."<<endl;
                head=new_node;
                new_node->next=nullptr;
                return;
            }

            Node * checker = head;
            while (head!=nullptr){
                checker=checker->next;
            }

            new_node->previous=checker;
            checker=new_node;

            //making DList tail points to this node as it's the last node 
            tail=new_node;

        }

        void delete_from_last(){
            if (head==nullptr){
                cout<<"dlist is empty ."<<endl;
                return;
            }

            if (tail!=nullptr)
            {
                tail=tail->previous;
                return;
            }

            Node * checker=head;
            while (checker!=nullptr)
            {
                checker=checker->next;
            }
            //making the node before last node ..points to nullptr
            checker->previous=nullptr




        }



};